#!/bin/bash

function log_clean () {
    echo "Cleaning in process!"
    cat $1 | head -n-1 | awk 'NF==2{print $1}' | xargs rm -rf
}
