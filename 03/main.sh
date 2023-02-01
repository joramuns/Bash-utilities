#!/bin/bash

source clean_options.sh
source make_clean.sh

if [[ $# -eq 1 ]]; then
    if [[ $1 -eq 1 ]]; then
        log_clean_opt
    elif [[ $1 -eq 2 ]]; then
        source get_date.sh
        date_time_opt
    elif [[ $1 -eq 3 ]]; then
        source generate_folder.sh
        mask_file_opt
    else
        echo "Wrong option selected!"
        exit 98
    fi
else
    echo "No option selected!"
    exit 99
fi

