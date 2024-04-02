#!/bin/bash

file_path="../include/outer_messages.h"
so_long_file="../include/so_long.h"
search_dir="../srcs/do_not_open/stop/i_warn_you/last_chance/secret_hell"

while IFS= read -r line; do
    if [[ "$line" == "# define"* && ! "$line" =~ "ifndef|endif" ]]; then
        # Extract variable and string after # define
        variable=$(echo "$line" | awk '{print $3}')
        string=$(echo "$line" | awk -F'\\\\n' '{print $2}')
        echo "Variable: $variable"
        echo "String: $string"

        # Encode variables with secret program
        encoded_string=$(./roba_inutile_di_lavoro/encriptor.out "$string")
        encoded_variable=$(./roba_inutile_di_lavoro/encriptor.out "$variable")

        echo "Decoded variable: $encoded_variable"
        echo "Decoded string: $encoded_string"

        # Replace variables with encoded ones
        sed -i '' "s/# define $variable \"\\\\n$string\\\\n\"/# define $encoded_variable \"\\\\n$encoded_string\\\\n\"/g" "$file_path"
		
		grep -rl "$variable" "$search_dir"/*.c | while read -r c_file; do
            echo "Found $variable in $c_file"
            sed -i '' "s/$variable/$encoded_variable/g" "$c_file"
            echo "Replaced variable in $c_file"
        done
    fi
done < "$file_path"

echo File succesfully encripted.
