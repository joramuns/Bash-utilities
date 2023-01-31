#!/bin/bash

source clean_options.sh
source make_clean.sh

if [[ $# -eq 1 ]]; then
    if [[ $1 -eq 1 ]]; then
        log_clean_opt
    elif [[ $1 -eq 2 ]]; then
        echo 2
    elif [[ $1 -eq 2 ]]; then
        echo 3
    fi
else
    echo "No option selected!"
    exit 99
fi

