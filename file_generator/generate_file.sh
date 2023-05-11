#!/bin/bash

# Temp define, folders and files should have different sizes and be defined separately

function file_init_pattern () {
    file_pattern=$(echo $1 | awk -F "." '{print $1}')
    file_extension=$(echo $1 | awk -F "." '{print $2}')
    MAXLENGTH=247
    (( MAXLENGTH-=${#file_extension} ))
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
    if [[ ${#filename} -lt 4 ]]; then
        get_count_file
        generate_filename
    else
        filename+=_$date_format
        filename+=.$file_extension
        get_count_file
    fi
}

function get_count_file () {
    ((pattern_counter[0]+=1))
    for (( n=0; n<=$pattern_len; n++ ))
    do
        check_arr_sum=$(IFS=+; echo "$((${pattern_counter[*]}))")
        if [[ ${pattern_counter[$n]} -gt 254 || $check_arr_sum -gt $MAXLENGTH ]]; then
            if [[ $n -eq $pattern_len ]]; then
                echo "No more filename combinations with this pattern"
                exit 1
            fi
            antiplagiat=1
            while [ ${file_pattern:$n:1} = ${file_pattern:$n+$antiplagiat:1} ]
            do
                (( antiplagiat+=1 ))
                if [[ $n+$antiplagiat -gt $pattern_len ]]; then
                    echo "No more filename combinations due to repeating letters"
                    exit 1
                fi
            done
            (( pattern_counter[n]=1 ))
            (( pattern_counter[n+antiplagiat]+=1 ))
        fi
    done
}
