#!/bin/bash

# Temp define, folders and files should have different sizes and be defined separately
MAXLENGTH=254

function file_init_pattern () {
    file_pattern=$(echo $1 | awk -F "." '{print $1}')
    file_extension=$(echo $1 | awk -F "." '{print $2}')
    pattern_counter=()
    (( pattern_len=${#file_pattern} - 1))
    for (( i=0; i<=$pattern_len; i++ ))
    do
        pattern_counter+=(1)
    done
}

function generate_filename () {
    filename=
    for (( i=0; i<=$pattern_len; i++ ))
    do
        letter_counter=${pattern_counter[$i]}
        for (( k=0; k<$letter_counter; k++ ))
        do
            filename+=${file_pattern:$i:1}
        done
    done
    echo $filename
    get_count
}

function get_count () {
    ((pattern_counter[0]+=1))
    for (( n=0; n<=$pattern_len; n++ ))
    do
        check_arr_sum=$(IFS=+; echo "$((${pattern_counter[*]}))")
        if [[ ${pattern_counter[$n]} -ge 254 || $check_arr_sum -gt $MAXLENGTH ]]; then
            if [[ $n -eq $pattern_len ]]; then
                echo "HOBA"
                exit 1
            fi
            (( pattern_counter[n]=1 ))
            (( pattern_counter[n+1]+=1 ))
        fi
    done
    # echo ${pattern_counter[@]}
}
