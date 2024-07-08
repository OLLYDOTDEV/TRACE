import argparse

def convert_gcode(input_file, output_file):
    with open(input_file, 'r') as file:
        lines = file.readlines()

    with open(output_file, 'w') as file:
        for line in lines:
            if line.startswith('G'):
                line = line.replace('U', 'A').replace('V', 'Z')
            file.write(line)

def main():
    parser = argparse.ArgumentParser(description='Convert G-code from XY UV to XY AZ.')
    parser.add_argument('input_file', type=str, help='The input G-code file.')
    parser.add_argument('output_file', type=str, help='The output G-code file.')

    args = parser.parse_args()

    convert_gcode(args.input_file, args.output_file)

if __name__ == '__main__':
    main()
