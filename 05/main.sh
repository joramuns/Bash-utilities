#!/bin/bash

green_color="\033[32m"
off_color="\033[0m"

# Timer is ON
time_start=$(date +"%s.%N")

total_num_folders=$[$(sudo find $1 -type d | wc -l)-1]
top5_folders=$(sudo du -chd1 $1 | sort -hr | awk 'NR>2' | head -5 | awk '{print $2", "$1}' | nl -s " - " -n ln -w 1)

# Generate list of all files
sudo find $1 -type f > .temp

# Use list
total_num_files=$(cat .temp | wc -l)
conf_num=$(grep ".conf" .temp | wc -l)
log_num=$(grep ".log" .temp | wc -l)

# Generate list of filetypes on list of files
sudo file -f .temp | awk '{$1 = ""; print $0}' > .typetemp

# Use list
text_num=$(grep "text$" .typetemp | wc -l)
exec_num=$(grep "executable" .typetemp | wc -l)
archive_num=$(grep "compressed" .typetemp | wc -l)

# Use find utility as exception to find symbolic links
link_num=$(sudo find $1 -type l | wc -l)

# Generate list of filesizes
sudo find $1 -type f -exec du -h {} + | awk '{print $2", "$1","}' > .sizetemp

# Generate list of executables
sudo find $1 -type f -executable -exec du -h {} + | awk '{print $2", "$1","}' > .execsizetemp

# Generate list of MD5 sums of executables
sudo find $1 -type f -executable -exec md5sum {} + | awk '{print $1}' > .execmd5sum

# Paste together sizes and types for all files and sizes and MD5 sums for executables
top10_files=$(paste .sizetemp .typetemp -d " " | sort -k 2 -rh | grep -vw -e "/.sizetemp," -e .temp -e "/.typetemp," | head -10 | nl -s " - " -n ln -w 1)
top10_exec_files=$(paste .execsizetemp .execmd5sum -d " " | sort -k 2 -rh | head -10 | nl -s " - " -n ln -w 1)

echo -e ${green_color}"Total number of folders (including all nested ones) = $total_num_folders"${off_color}
echo "TOP 5 folders of maximum size arranged in descending order (path and size):"
echo "$top5_folders"
echo -e ${green_color}"Total number of files = $total_num_files"${off_color}
echo "Number of:"
echo "Configuration files (with the .conf extension) = $conf_num"
echo "Text files = $text_num"
echo "Executable files = $exec_num"
echo "Log files (with the extension .log) = $log_num"
echo "Archive files = $archive_num"
echo "Symbolic links = $link_num"
echo -e ${green_color}"TOP 10 files of maximum size arranged in descending order (path, size and type):"${off_color}
echo "$top10_files"
echo -e ${green_color}"TOP 10 executable files of the maximum size arranged in descending order (path, size and MD5 hash of file)"${off_color}
echo "$top10_exec_files"

# Timer is OFF
time_end=$(date +"%s.%N")
total_time=$(echo "$time_end - $time_start" | bc | awk '{printf "%.2f", $1}')
echo -e ${green_color}"Script execution time (in seconds) = $total_time"${off_color}

# Clean trash
sudo rm .temp .typetemp .sizetemp .execsizetemp .execmd5sum
