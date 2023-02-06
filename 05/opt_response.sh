#!/bin/bash

files=$(find . -name "*.log")
codes=($(./get_response_codes.awk $files))
for (( io_response=0; io_response < ${#codes[@]}; io_response++))
do
    ./response.awk -v i_code=${codes[$io_response]} $files
done
