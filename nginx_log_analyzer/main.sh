#!/bin/bash
source options.sh
re="^[1-4]{1}$"

if [[ $# -ne 1 || ! $1 =~ $re ]]; then
    echo "Invalid input!"
elif [ $1 -eq 1 ]; then
    opt_sort_response
elif [ $1 -eq 2 ]; then
    opt_uniq_ip
elif [ $1 -eq 3 ]; then
    opt_err_req
elif [ $1 -eq 4 ]; then
    opt_uniq_err_req
fi
