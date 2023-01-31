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
