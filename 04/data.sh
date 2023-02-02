#!/bin/bash

resp_result=(200 201 400 401 403 404 500 501 502 503)
meth_result=(GET POST PUT PATCH DELETE)
#
#
ag_result=("Mozilla" "Google Chrome" "Opera" "Safari" "Internet Explorer" "Microsoft Edge" "Crawler and bot" "Library and net tool")

function get_random () {
    echo $(shuf -i $1-$2 -n 1)
    # rand_result=$(( ($RANDOM % $2) + $1 ))
    # if (( $rand_result > $2 )); then
    #     get_random $1 $2
    # else
    #     echo $rand_result
    # fi
}

function get_ip () {
    ip_result=$(get_random 1 255)
    for (( ip_i = 0; i < 3; i++ ))
    do
        ip_result+=.$(get_random 1 255)
    done
    echo $ip_result
}

function get_response () {
    echo ${resp_result[$(get_random 0 9)]}
}

function get_method () {
    echo ${meth_result[$(get_random 0 4)]}
}

function get_date () {
    echo Kek
}

function get_url () {
    echo Kok
}

function get_agent () {
    echo ${ag_result[$(get_random 0 7)]}
}
