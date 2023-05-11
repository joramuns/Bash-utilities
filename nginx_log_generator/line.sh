#!/bin/bash

source data.sh
source time.sh

function get_line () {
    echo -n "$(get_ip) "
    echo -n "- "
    echo -n "- "
    echo -n "[$(clf_date ${sorted_datetime_array[$1]})] "
    echo -n "\"$(get_method)\" "
    echo -n "$(get_response) "
    echo -n "$(get_random 1 5000) "
    echo -n "\"$(get_url)\" "
    echo "\"$(get_agent)\""
}

function make_log () {
    init_day $1

    for (( l_i=0; l_i < $1; l_i++ ))
    do
        get_line $l_i
    done
}
