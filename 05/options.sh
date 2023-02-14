#!/bin/bash

files=$(find . -name "*.log")

if [ -z "$files" ]; then
    echo "No log files in folder!"
    exit 13
fi

function opt_sort_response () {
    codes=($(./get_response_codes.awk $files))
    for (( io_response=0; io_response < ${#codes[@]}; io_response++))
    do
        ./response.awk -v i_code=${codes[$io_response]} $files
    done
}

function opt_uniq_ip () {
    ./uniq_ip.awk $files
}

function opt_err_req () {
    ./err_req.awk $files
}

function opt_uniq_err_req () {
    ./err_req.awk $files | ./uniq_ip.awk
}
