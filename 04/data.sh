#!/bin/bash


function get_random () {
    echo $(shuf -i $1-$2 -n 1)
}

function get_ip () {
    local ip_result=$(get_random 1 255)
    for (( ip_i = 0; i < 3; i++ ))
    do
        ip_result+=.$(get_random 1 255)
    done
    echo $ip_result
}

function get_response () {
    local resp_result=(200 201 400 401 403 404 500 501 502 503)
    echo ${resp_result[$(get_random 0 9)]}
}

function get_method () {
    local meth_result=(GET POST PUT PATCH DELETE)
    echo ${meth_result[$(get_random 0 4)]}
}

function get_date () {
    echo Kek
}

function get_url () {
    local extensions=(ru com eu edu gov)
    local rand_url=$(cat /dev/urandom | tr -dc '[:alpha:]' | fold -w ${3:-$(get_random 1 10)} | head -n 1)
    rand_url+=.${extensions[$(get_random 0 4)]}
    echo $rand_url
}

function get_agent () {
    local ag_result=("Mozilla" "Google Chrome" "Opera" "Safari" "Internet Explorer" "Microsoft Edge" "Crawler and bot" "Library and net tool")
    echo ${ag_result[$(get_random 0 7)]}
}
