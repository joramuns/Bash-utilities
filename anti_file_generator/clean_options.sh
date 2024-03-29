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
    if ! [ -f "statx" ]; then
        echo "Statx utility required. You can compile it with make and gcc from source included."
        exit 97
    fi
    read -p "Enter start date (example 12-JAN-2023 11:21): " startdate
    check_date "$startdate"
    startdate=$(date -d "$startdate" +%s)
    read -p "Enter end date (example 12-JAN-2023 11:21): " enddate
    check_date "$enddate"
    enddate=$(date -d "$enddate" +%s)
    check_period $startdate $enddate
    echo "Cleaning by date period in process!"
    date_clean $startdate $enddate
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
