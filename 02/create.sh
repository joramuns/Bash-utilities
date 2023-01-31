#!/bin/bash

function start_create () {
    folder_init_pattern $1
    for (( m=0; m<$folder_num; m++ ))
    do
        get_path
        generate_folder
        echo $path_21
        mkdir -p $path_21/$foldername
        echo "$(realpath $path_21/$foldername) $(date +%d.%m.%y)" >> log.txt
        file_init_pattern $2
        # file_num=$(( $RANDOM % 1000 + 1 ))
        file_num=3
        for (( p=0; p<$file_num; p++ ))
        do
            generate_filename
            fallocate $path_21/$foldername/$filename -l $3
            echo "$(realpath $path_21/$foldername/$filename) $(date +%d.%m.%y) $3" >> log.txt
            space_left=$(df -m / | tail -1 | awk '{print $4}')
            if (( space_left < 1024 )); then
                echo "Less than 1GB of free space remaining!"
                exit 99
            fi
        done
    done
}

function get_path () {
    path_21=$(find ~ -type d | shuf -n 1)
}
