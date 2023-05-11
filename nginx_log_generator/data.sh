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

# Response codes definition:
# 200 OK
# 201 Created
# 400 Bad request
# 401 Unauthorized
# 403 Forbidden
# 404 Not found
# 500 Internal server error
# 501 Not implemented
# 502 Bad gateway
# 503 Service unavailable
function get_response () {
    local resp_result=(200 201 400 401 403 404 500 501 502 503)
    (( num_resp=${#resp_result[@]} - 1))
    echo ${resp_result[$(get_random 0 $num_resp)]}
}

function get_method () {
    local meth_result=(GET POST PUT PATCH DELETE)
    (( num_meth=${#meth_result[@]} - 1 ))
    echo ${meth_result[$(get_random 0 $num_meth)]}
}

function get_url () {
    local extensions=(ru com eu edu gov)
    (( num_extensions=${#extensions[@]} - 1 ))
    local rand_url=$(cat /dev/urandom | tr -dc '[:alpha:]' | fold -w ${3:-$(get_random 1 10)} | head -n 1)
    rand_url+=.${extensions[$(get_random 0 $num_extensions)]}
    echo $rand_url
}

function get_agent () {
    local ag_result=("Mozilla" "Google Chrome" "Opera" "Safari" "Internet Explorer" "Microsoft Edge" "Crawler and bot" "Library and net tool")
    (( num_ag=${#ag_result[@]} - 1 ))
    echo ${ag_result[$(get_random 0 $num_ag)]}
}
