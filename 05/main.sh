#!/bin/bash

time_start=$(date +"%s.%N")
total_num_folders=$[$(sudo find $1 -type d | wc -l)-1]
top5_folders=$(sudo du -chd1 $1 | head -n -2 | head -5 | sort -hr | awk '{print "- "$2", "$1}' | nl)
total_num_files=$(sudo find $1 -type f | wc -l)
#
#
#
#
#
top10_files=

echo "Total number of folders (including all nested ones) = $total_num_folders"
echo "TOP 5 folders of maximum size arranged in descending order (path and size):"
echo "$top5_folders"
echo "Total number of files = $total_num_files"
echo "Number of:"
echo "Text files = "
echo "Executable files = "
echo "Log files (with the extension .log) = "
echo "Archive files = "
echo "Symbolic links = "
#
#
#
#
#
echo "TOP 10 files of maximum size arranged in descending order (path, size and type):"
echo "$top10_files"
echo "TOP 10 executable files of the maximum size arranged in descending order (path, size and MD5 hash of file)"
#

time_end=$(date +"%s.%N")
total_time=$(echo "$time_end - $time_start" | bc | awk '{printf "%.2f", $1}')
echo "Script execution time (in seconds) = $total_time"
