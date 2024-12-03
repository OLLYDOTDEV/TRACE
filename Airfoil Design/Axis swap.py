import argparse
import os

def convert_gcode(input_file, output_file):
    with open(input_file, 'r') as file:
        lines = file.readlines()

    with open(output_file, 'w') as file:
        for line in lines:
            if line.startswith('G'):
                line = line.replace('U', 'Z').replace('V', 'A')
            file.write(line)

def main():
    parser = argparse.ArgumentParser(description='Convert G-code from XY UV to XY ZA.')
    parser.add_argument('input_file', type=str, help='The input G-code file.')

    args = parser.parse_args()

    # Change the output file name to include (XYAZ) and have .nc extension
    base_name = os.path.splitext(args.input_file)[0]
    output_file = f"{base_name} (XYAZ).nc"

    convert_gcode(args.input_file, output_file)
    print(f"Converted file saved as {output_file}")

if __name__ == '__main__':
    main()
