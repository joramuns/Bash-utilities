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
source check_input.sh

if [[ $check_counter -eq 6 ]]; then
    start_create $1 $2 $3 $4 $5 $6
fi

