% Based off a video from James D. Whiteside https://www.youtube.com/watch?v=QNS0LrlRHbs
% Code by Oliver Bell
% 05/09/2024
clc;
clear;

fig = figure(1);  % Use figure identifier '1'
set(fig, 'Position', [100, 100, 800, 600]);  % Set figure position and size
clf;

% ------ User Parameters Editing Start ------
Tend_Temperature_Target = 220; % C
Tamb_Temperature = 20; % C
T0_Temperature = Tamb_Temperature;
Distance = 1; % m
V_Supply = 19.5; % V
air_velocity = 0.01; % m/s

% PID Constants
Kp = Distance/10;
Ki = Distance/1000;
Kd = Distance/1000;

% Simulation Control
Simulation_Duration = 60; % s
Simulation_Resolution_Per_Seconds = 1000;
PWM_Frequency = 100; % Hz
% ------ User Parameters Editing Stops ------

Simulation_Step_Size = Simulation_Duration / Simulation_Resolution_Per_Seconds;

% Nichrome constants 
NiCr_Resistvity = 1.10E-06;
NiCr_Density = 8400; % kg/m^3
Cp_NiCr_Specific_Heat_Capacity = 460; % J/(kg*C)

% Constants for radiation
sigma = 5.67e-8; % Stefan-Boltzmann constant
emissivity = 0.8; % Approximate emissivity for nichrome

% Air properties at 20°C
rho = 1.204;      % Density (kg/m^3)
mu = 1.825e-5;    % Dynamic viscosity (kg/(m·s))
k = 0.0257;       % Thermal conductivity (W/(m·K))
Pr = 0.713;       % Prandtl number

% Different gauges to simulate
gauges = 20:34;

% Initialize arrays to store results
num_steps = Simulation_Duration / Simulation_Step_Size;
T_all = zeros(length(gauges), num_steps);
PWM_all = zeros(length(gauges), num_steps);

% Loop through each gauge
for g = 1:length(gauges)
    Gauge = gauges(g);

    % Intrinsic values of the wire
    d_diameter = (0.127 * 92^((36 - Gauge) / 39))/1000;  % m
    A_Cross_Section = pi * (d_diameter/2)^2; % m^2
    A_Surface_Area = Distance * d_diameter * pi; % m^2
    V_Volume = A_Cross_Section * Distance; % m^3
    M_Mass = V_Volume * NiCr_Density; % kg

    % Electrical Properties
    R_Resistance_Per_Meter = NiCr_Resistvity / A_Cross_Section;  % Ω/m
    R_Resistance_Total = R_Resistance_Per_Meter * Distance;
    I_Current = V_Supply / R_Resistance_Total;
    P_Max_Power = V_Supply * I_Current;

    % Calculate convective heat transfer coefficient
    D = d_diameter;
    
    % Calculate Reynolds number
    Re = (rho * air_velocity * D) / mu;
    
    % Calculate Nusselt number using Churchill and Bernstein correlation
    Nu = 0.3 + ((0.62 * Re^0.5 * Pr^(1/3)) / (1 + (0.4/Pr)^(2/3))^0.25) * ...
         (1 + (Re/282000)^(5/8))^(4/5);
    
    % Calculate convective heat transfer coefficient
    h = (Nu * k) / D;

    % Initialize variables for PID control
    error = 0;
    previous_error = 0;
    integral = 0;
    derivative = 0;
    duty_cycle = 0; % Initial duty cycle

    % Initialize temperature and PWM arrays
    T = zeros(1, num_steps);
    PWM = zeros(1, num_steps);
    T(1) = T0_Temperature;

    % Simulation loop
    for i = 2:num_steps
        % Calculate PID control
        error = Tend_Temperature_Target - T(i-1);
        integral = integral + error * Simulation_Step_Size;
        derivative = (error - previous_error) / Simulation_Step_Size;
        control_output = Kp * error + Ki * integral + Kd * derivative;

        % Constrain the control output to be between 0 and 1 (represents duty cycle)
        duty_cycle = min(max(control_output, 0), 1);
        PWM(i) = duty_cycle; % Store PWM signal for plotting

        % Calculate the effective power input using the duty cycle
        P_Power = P_Max_Power * duty_cycle^2;

        % Energy in
        J_Energy_In = P_Power * Simulation_Step_Size;

        % Energy out - Convection
        J_Energy_Convection = h * A_Surface_Area * (T(i-1) - Tamb_Temperature) * Simulation_Step_Size;

        % Energy out - Radiation
        J_Energy_Radiation = emissivity * A_Surface_Area * sigma * ...
            ((T(i-1) + 273.15)^4 - (Tamb_Temperature + 273.15)^4) * Simulation_Step_Size;

        % Net energy
        J_Energy_Net = J_Energy_In - J_Energy_Convection - J_Energy_Radiation;

        % Temperature change
        delta_T = J_Energy_Net / (M_Mass * Cp_NiCr_Specific_Heat_Capacity);

        % New temperature
        T(i) = T(i-1) + delta_T;

        % Update previous error
        previous_error = error;
    end

    % Store results for the current gauge
    T_all(g, :) = T;
    PWM_all(g, :) = PWM;

    % Display final temperature for this gauge
    fprintf('Final wire temperature for Gauge %d: %.2f °C\n', Gauge, T(end));
end

% Time array for plotting
time = 0:Simulation_Step_Size:Simulation_Duration-Simulation_Step_Size;

% Plotting all temperature curves on the same graph
figure(1);  % Use figure identifier '1'

% Plot Temperature Over Time
subplot(2,1,1);
hold on;
for g = 1:length(gauges)
    plot(time, T_all(g, :), 'LineWidth', 1.5);
end
hold off;
xlabel('Time (s)', 'FontSize', 12);
ylabel('Temperature (°C)', 'FontSize', 12);
title('Wire Temperature Over Time with PID Control', 'FontSize', 14);
yline(Tend_Temperature_Target, '--r', 'Target Temperature'); % Add horizontal line at the target setpoint
grid on;
legend(arrayfun(@(x) sprintf('Gauge %d', x), gauges, 'UniformOutput', false), 'Location', 'southeast');

% Plot PWM Over Time
subplot(2,1,2);
hold on;
for g = 1:length(gauges)
    plot(time, PWM_all(g, :), 'LineWidth', 1.5);
end
hold off;
xlabel('Time (s)', 'FontSize', 12);
ylabel('PWM Duty Cycle', 'FontSize', 12);
title('PWM Signal Over Time for Different Gauges', 'FontSize', 14);
grid on;
legend(arrayfun(@(x) sprintf('Gauge %d', x), gauges, 'UniformOutput', false), 'Location', 'northeast');

% Adjust the layout
sgtitle('Nichrome Wire Heating Simulation for Different Gauges', 'FontSize', 16);
set(gcf, 'Color', 'w');  % Set background color to white


