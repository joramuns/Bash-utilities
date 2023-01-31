#!/bin/bash

function start_create () {
    folder_init_pattern $3
    for (( m=0; m<$2; m++ ))
    do
        generate_folder
        mkdir -p $1/$foldername
        echo "$(realpath $1/$foldername) $(date +%d.%m.%y)" >> log.txt
        file_init_pattern $5
        for (( p=0; p<$4; p++ ))
        do
            generate_filename
            fallocate $1/$foldername/$filename -l $6
            echo "$(realpath $1/$foldername/$filename) $(date +%d.%m.%y) $6" >> log.txt
            space_left=$(df -m / | tail -1 | awk '{print $4}')
            if (( space_left < 1024 )); then
                echo "Less than 1GB of free space remaining!"
                exit 99
            fi
        done
    done
}
