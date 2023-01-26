#!/bin/bash

# 1 Path
# 2 Number of subfolders
# 3 Folder names
# 4 Number of files
# 5 Filename pattern
# 6 File size

source create.sh
source generate_file.sh
source generate_folder.sh

space_avail=$(df / | tail -1 | awk '{print $4}')

# if [[ $# -ne 6 ]]; then
# 	echo "Not enough arguments!"
#     exit 1
# else
	source check_input.sh
# fi

if [[ $check_counter -ne 6 ]]; then
    exit 1
fi

folder_init_pattern $3
for (( m=0; m<$2; m++ ))
do
    generate_folder
    file_init_pattern $5
    for (( p=0; p<$4; p++ ))
    do
        generate_filename
        echo $foldername/$filename
    done
done
