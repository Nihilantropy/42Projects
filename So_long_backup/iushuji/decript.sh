#!/bin/bash

file_path="../include/outer_messages.h"
search_dir="../srcs/do_not_open/stop/i_warn_you/last_chance/secret_hell/secret_srcs"

while IFS= read -r line; do
    if [[ "$line" == "# define"* && ! "$line" =~ "ifndef|endif" ]]; then
		# Extract variable and string after # define
        variable=$(echo "$line" | awk '{print $3}')
        string=$(echo "$line" | awk -F'\\\\n' '{print $2}')
        echo "Variable: $variable"
        echo "String: $string"

        # Decode variables with secret program
        decoded_string=$(./roba_inutile_di_lavoro/decriptor.out "$string")
        decoded_variable=$(./roba_inutile_di_lavoro/decriptor.out "$variable")

        echo "Decoded variable: $decoded_variable"
        echo "Decoded string: $decoded_string"

        # Replace variables with Decoded ones
		sed -i '' "s/# define $variable \"\\\\n$string\\\\n\"/# define $decoded_variable \"\\\\n$decoded_string\\\\n\"/g" "$file_path"
		
		grep -rl "$variable" "$search_dir"/*.c | while read -r c_file; do
            echo "Found $variable in $c_file"
            sed -i '' "s/$variable/$decoded_variable/g" "$c_file"
            echo "Replaced variable in $c_file"
        done
    fi
done < "$file_path"

echo File succesfully decripted
