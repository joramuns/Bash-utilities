#!/bin/bash

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
