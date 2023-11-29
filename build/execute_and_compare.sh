#!/bin/bash

# File paths
input_file="../infile"
output_file="../outfile"
temp_file="temp_output.txt"

# Clear the output file
> "$output_file"

# Construct the shell pipeline command
shell_command="< $input_file "
for cmd in "$@"; do
    shell_command+="$cmd | "
done
shell_command+=" cat"

# Execute the shell pipeline command and save the output
eval $shell_command > $temp_file

# Construct and execute the pipex command
pipex_command="../pipex $input_file "
for cmd in "$@"; do
    pipex_command+='"'$cmd'" '
done
pipex_command+="$output_file"

# Execute the pipex command
eval $pipex_command

# Compare outputs
if cmp -s "$temp_file" "$output_file"; then
    echo "✅ Outputs match"
else
    echo "❌ Outputs do not match"
fi

# Clean up
rm -f $temp_file
