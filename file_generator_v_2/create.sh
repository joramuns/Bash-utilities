#!/bin/bash

function start_create () {
    folder_init_pattern $1
    for (( m=0; m<$folder_num; m++ ))
    do
        get_path
        generate_folder
        mkdir -p $path_21/$foldername
        echo "$(realpath $path_21/$foldername) $(date +%d.%m.%y)" >> log.txt
        file_init_pattern $2
        file_num=$(( $RANDOM % 10000 + 1 ))
        for (( p=0; p<$file_num; p++ ))
        do
            generate_filename
            fallocate $path_21/$foldername/$filename -l $3
            echo "$(realpath $path_21/$foldername/$filename) $(date +%d.%m.%y) $3" >> log.txt
            space_left=$(df -m / | tail -1 | awk '{print $4}')
            if (( space_left < 1024 )); then
                echo "Less than 1GB of free space remaining!"
                end_log
                exit 99
            fi
        done
    done
}

function get_path () {
    path_21=$(find ~ -type d | grep -e "bin" -e "sbin" -v | shuf -n 1)
    if ! [ -w $path_21 ]; then
        get_path
    fi
}

function end_log () {
    timer_end=$(date +"%s.%N")
    total_time=$(echo "$timer_end - $timer_start" | bc | awk '{printf "%.2f", $1}')
    end_time=$(date +"%T")
    echo "Start time: $start_time, End time: $end_time, Total running $total_time seconds" >> log.txt
}
