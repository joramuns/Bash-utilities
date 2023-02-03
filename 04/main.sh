#!/bin/bash

source line.sh

num_files=1
num_lines=$(get_random 100 1000)

for (( m_i=0; m_i < $num_files; m_i++ ))
do
    make_log $num_lines
done

