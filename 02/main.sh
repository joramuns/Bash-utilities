#!/bin/bash

# 1 Folder names
# 2 Filename pattern
# 3 File size

timer_start=$(date +"%s.%N")
start_time=$(date +"%T")
source create.sh
source generate_file.sh
source generate_folder.sh
source check_input.sh

if [[ $check_counter -eq 3 ]]; then
    start_create $1 $2 $3
    timer_end=$(date +"%s.%N")
    total_time=$(echo "$timer_end - $timer_start" | bc | awk '{printf "%.2f", $1}')
    end_time=$(date +"%T")
    echo "Start time: $start_time, End time: $end_time, Total running $total_time seconds" >> log.txt
fi

