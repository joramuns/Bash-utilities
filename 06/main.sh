#!/bin/bash
source options.sh
re="^[1-4]{1}$"
files=$(find . -name "*.log")

if [[ $# -ne 1 || ! $1 =~ $re ]]; then
    echo "Invalid input!"
elif [ $1 -eq 1 ]; then
    sudo goaccess $files -p goaccess1.conf
elif [ $1 -eq 2 ]; then
    sudo goaccess $files -p goaccess2.conf
elif [ $1 -eq 3 ]; then
    sudo goaccess $files -p goaccess3.conf
elif [ $1 -eq 4 ]; then
    sudo goaccess $files -p goaccess4.conf
fi
