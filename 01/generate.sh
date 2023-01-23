#!/bin/bash

function file_init_pattern () {
    file_pattern=$(echo $1 | awk -F "." '{print $1}')
    file_extension=$(echo $1 | awk -F "." '{print $2}')
    pattern_counter=0
    pattern_len=${#file_pattern}
    for (( i=1; i<=$pattern_len; i++ ))
    do
        (( pattern_counter=pattern_counter * 10 + 1 ))
    done
}

function generate_filename () {
    filename=
    for (( i=0; i<$pattern_len; i++ ))
    do
        letter_counter=${pattern_counter:$i:1}
        for (( k=0; k<$letter_counter; k++ ))
        do
            filename+=${file_pattern:$i:1}
        done
    done
    echo $filename
    (( pattern_counter = pattern_counter + 1 ))
}
