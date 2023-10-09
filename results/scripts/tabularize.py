import argparse

# Create an argument parser
parser = argparse.ArgumentParser(description='Format a .dat file as a tabular format.')

# Add an argument for the file path
parser.add_argument('file_path', help='Path to the .dat file to be formatted')

# Parse the command-line arguments
args = parser.parse_args()

# Read the data from the specified file
with open(args.file_path, 'r') as file:
    lines = file.readlines()

# Define column headers
headers = lines[0].split('\t')

# Find the maximum width for each column except the last one
column_widths = [max(len(header), max(len(line.split('\t')[i]) for line in lines[1:])) for i, header in enumerate(headers[:-1])]

# Format the data
formatted_data = []

# Format headers with tabs and proper padding except for the last column
formatted_headers = [header.ljust(width) for header, width in zip(headers[:-1], column_widths)]
formatted_headers.append(headers[-1])  # Add the last header without padding
formatted_data.append('\t'.join(formatted_headers))

# Loop through the remaining lines and format each line with tabs and proper padding except for the last column
for line in lines[1:]:
    elements = line.split('\t')
    formatted_line = '\t'.join(element.ljust(width) for element, width in zip(elements[:-1], column_widths))
    formatted_line += '\t' + elements[-1]  # Add the last element without padding
    formatted_data.append(formatted_line)

# Write the formatted data back to the same file without newlines between rows
with open(args.file_path, 'w') as file:
    file.write('\n'.join(formatted_data))


# Write the formatted data back to the same file without newlines between rows
with open(args.file_path, 'w') as file:
    file.writelines(formatted_data)
