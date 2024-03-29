#!/bin/bash

function log_clean () {
    echo "Cleaning by logfile in process!"
    cat $1 | head -n-1 | awk 'NF==2{print $1}' | xargs rm -rf
}

function date_clean () {
    find ~ -type d | awk \
    -v startdate="$startdate" \
    -v enddate="$enddate" \
    '{
        cmd = "./statx " $1
        cmd | getline birthdate
        if (enddate > birthdate && birthdate > startdate && $1 ~ /[_]{1}[0-9]{6}$/) {
            system("rm -rf " $1)
        }
        close(cmd)
    }'
}

function mask_file_clean () {
    echo "Cleaning by file mask in process!"
    pattern=$(echo $1 | awk -F "_" '{print $1}')
    appendix=$(echo $1 | awk -F "_" '{print $2}')
    folder_init_pattern $pattern
    while (true)
    do
        generate_folder
        find ~ -name $foldername -exec rm -rf {} +
    done
}
