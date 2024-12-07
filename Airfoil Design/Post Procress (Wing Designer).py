import os

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


        # print arrays
        for x in first_section:
            print(x)
        for x in second_section:
            print(x)

        # Combine both arrays
        new_contents = "\n".join(first_section + second_section)

        # Define the output file path
        output_file_path = os.path.splitext(file_path)[0] + "_processed.gcode"

        # Write to the new file
        with open(output_file_path, 'w') as output_file:
            output_file.write(new_contents)

        print(f"Processed file saved to: {output_file_path}")

    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    file_path = input("Enter the path to the file: ").strip()
    if os.path.exists(file_path):
        process_file(file_path)
    else:
        print("File does not exist. Please provide a valid file path.")
