#!/bin/bash

start_date="1995-01-01"
end_date=$(date +%Y-%m-%d)

function get_day () {
    rand_day=$(shuf -i $(get_sec_day $start_date)-$(get_sec_day $end_date) -n 1)
    rand_formatted_day=$(get_hyphen_day $rand_day)
    day_result=$(get_sec_day $rand_formatted_day)
    echo $day_result
}

function get_sec_day () {
    echo $(date -d $1 +%s)
}

function get_hyphen_day () {
    echo $(date -d @$1 +%Y-%m-%d)
}

function clf_date () {
    echo $(date -d @$1 +"%d/%b/%Y:%H:%M:%S")
}
