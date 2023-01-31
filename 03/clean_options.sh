#!/bin/bash

function log_clean_opt () {
    read -p "Enter log file name: " -a logfile
    if [ -f $logfile ]; then
        log_clean $logfile
    else
        echo "There is no such file: $logfile"
        exit 1
    fi
}

function date_time_opt () {
    echo "Not implemented"
}

function mask_file_opt () {
    read -p "Enter foldername mask: " -a maskfile
    re='^[a-zA-Z]{1,7}[_][0-9]{6}$'
    if [[ $maskfile =~ $re ]]; then
        mask_file_clean $maskfile
    else
        echo "Wrong folder name mask!"
        exit 2
    fi
}
