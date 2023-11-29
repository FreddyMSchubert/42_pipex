#!/bin/bash

# File paths
input_file="../infile"
output_file="../outfile"

# Check if infile and outfile exist, create them if not
[ -f "$input_file" ] || touch "$input_file"
[ -f "$output_file" ] || touch "$output_file"

# Check for the argument
if [ -z "$1" ]; then
    echo "Please specify the length of the random string."
    exit 1
fi

# Build project
make fcomp

# Generate random string of specified length
random_string=$(awk -v len=$1 'BEGIN {
    srand();
    chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    str = "";
    for (i = 1; i <= len; i++)
	{
		if (i % 50 == 0)
			str = str "\n";
        str = str substr(chars, int(rand() * length(chars)) + 1, 1);
    }
    print str;
}')

# Add the random string to input_file
echo "$random_string" > "$input_file"

# Clear the output file
> "$output_file"
