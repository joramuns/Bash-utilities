#!/bin/bash

# 1 Path
# 2 Number of subfolders
# 3 Folder names
# 4 Number of files
# 5 Filename pattern
# 6 File size

source create.sh
source generate.sh

space_avail=$(df / | tail -1 | awk '{print $4}')

if [[ $# -ne 6 ]]; then
	echo "Not enough arguments!"
    exit 1
else
	source check_input.sh
fi

if [[ $check_counter -ne 6 ]]; then
    exit 1
fi

file_init_pattern $5
for i in {1..99999}
do
    generate_filename
done

