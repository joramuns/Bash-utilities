#!/bin/bash

start_date="1995-01-01"
end_date=$(date +%Y-%m-%d)

function init_day () {
    local datetime_array=()
    local rand_day=$(get_day)

    for (( lh_i=0; lh_i < $1; lh_i++ ))
    do
        (( rand_time=$rand_day+$(get_random 1 86399) ))
        datetime_array+=($rand_time)
    done
    sorted_datetime_array=($(printf "%s\n" "${datetime_array[@]}" | sort -n))
}

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
    echo $(date -d @$1 +"%d/%b/%Y:%H:%M:%S %z")
}
