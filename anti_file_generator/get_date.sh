#!/bin/bash

function check_date () {
    monthes=JAN\|FEB\|MAR\|APR\|MAY\|JUN\|JUL\|AUG\|SEP\|NOV\|DEC
    re="[0-9]{2}[-]{1}"$monthes"[-]{1}[0-9]{4}[ ]{1}[0-9]{2}[:]{1}[0-9]{2}$"
    if ! [[ $1 =~ $re ]]; then
        echo "Wrong date format!"
        exit 13
    fi
}

function check_period () {
    if [[ $1 -eq $2 ]]; then
        echo "The dates are the same, error!"
        exit 14
    elif [[ $1 -gt $2 ]]; then
        echo "End date should always come after start date!"
        exit 15
    fi
}
