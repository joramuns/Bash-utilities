#!/bin/bash

source line.sh
source time.sh

num_lines=10
rand_day=$(get_day)
datetime_array=()

for (( m_i=0; m_i < $num_lines; m_i++ ))
do
    (( rand_time=$rand_day+$(get_random 1 86399) ))
    datetime_array+=($rand_time)
done

sorted_datetime_array=($(printf "%s\n" "${datetime_array[@]}" | sort -n))

for (( m_i=0; m_i < $num_lines; m_i++ ))
do
    get_line
done

