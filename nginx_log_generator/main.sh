#!/bin/bash

source line.sh

num_files=5

for (( m_i=0; m_i < $num_files; m_i++ ))
do
    filename="nginx"$m_i".log"
    num_lines=$(get_random 100 1000)
    make_log $num_lines > $filename
done

