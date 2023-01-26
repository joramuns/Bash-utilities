#!/bin/bash

# Temp define, folders and files should have different sizes and be defined separately
MAXLENGTH_FOLDER=254

function folder_init_pattern () {
    folder_pattern=$1
    folder_pattern_counter=()
    (( folder_pattern_len=${#folder_pattern} - 1))
    for (( i=0; i<=$folder_pattern_len; i++ ))
    do
        folder_pattern_counter+=(1)
    done
}

function generate_folder () {
    foldername=
    for (( i=0; i<=$folder_pattern_len; i++ ))
    do
        folder_letter_counter=${folder_pattern_counter[$i]}
        for (( k=0; k<$folder_letter_counter; k++ ))
        do
            foldername+=${folder_pattern:$i:1}
        done
    done
    get_count_folder
}

function get_count_folder () {
    (( folder_pattern_counter[0]+=1 ))
    for (( n=0; n<=$folder_pattern_len; n++ ))
    do
        folder_check_arr_sum=$(IFS=+; echo "$((${folder_pattern_counter[*]}))")
        if [[ ${folder_pattern_counter[$n]} -ge 254 || $folder_check_arr_sum -gt $MAXLENGTH_FOLDER ]]; then
            if [[ $n -eq $folder_pattern_len ]]; then
                echo "No more folder combinations with this pattern"
                exit 1
            fi
            (( folder_pattern_counter[n]=1 ))
            (( folder_pattern_counter[n+1]+=1 ))
        fi
    done
}