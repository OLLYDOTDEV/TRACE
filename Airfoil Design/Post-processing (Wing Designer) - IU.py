import os
import tkinter as tk
from tkinter import filedialog, messagebox

def process_file(file_path):
    try:
        # Read the file contents
        with open(file_path, 'r') as file:
            lines = file.readlines()

        # Arrays for the two sections
        first_section = []
        second_section = []

        # First search: Add all lines to the array until the first line that starts with "G1 ", then remove the last entry
        for line in lines:
            if line.strip().startswith("G1 "):
                break
            first_section.append(line.strip())
        if first_section:
            first_section.pop()  # Remove the last entry

        # Modify the first section: Remove second-to-last element and append "G1 " to the last element
        if len(first_section) > 1:
            first_section.pop(-2)  # Remove the second-to-last element
            first_section[-1] = f"G1 {first_section[-1]}"  # Append "G1 " to the last element

        # Second search: Start from the line before the first G1 and add all lines after
        g1_index = next((i for i, line in enumerate(lines) if "G1 " in line), None)
        if g1_index is not None and g1_index > 0:
            second_section = [line.strip() for line in lines[g1_index - 1:]]

        # Reverse the second section
        second_section.reverse()

        # Combine both arrays
        new_contents = "\n".join(first_section + second_section)

        # Define the output file path
        output_file_path = os.path.splitext(file_path)[0] + "_processed.gcode"

        # Write to the new file
        with open(output_file_path, 'w') as output_file:
            output_file.write(new_contents)

        messagebox.showinfo("Success", f"Processed file saved to: {output_file_path}")

    except Exception as e:
        messagebox.showerror("Error", f"An error occurred: {e}")

def select_file():
    file_path = filedialog.askopenfilename(
        title="Select G-code File",
        filetypes=[("G-code Files", "*.*"), ("All Files", "*.*")]
    )
    if file_path:
        process_file(file_path)

def main():
    root = tk.Tk()
    root.title("G-code Processor")

    frame = tk.Frame(root, padx=10, pady=10)
    frame.pack(padx=10, pady=10)

    label = tk.Label(frame, text="Select a G-code file to process:")
    label.pack(pady=5)

    select_button = tk.Button(frame, text="Select File", command=select_file)
    select_button.pack(pady=5)

    quit_button = tk.Button(frame, text="Quit", command=root.quit)
    quit_button.pack(pady=5)

    root.mainloop()

if __name__ == "__main__":
    main()
