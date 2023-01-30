#!/bin/bash

check_counter=0

# 1 Path
if [ -d "$1" ]; then
	check_counter=$((check_counter+1))
else
	echo "1: Wrong path!"
fi
# 2 Number of subfolders
re='^[0-9]+$'
if [[ $2 =~ $re ]]; then
	check_counter=$((check_counter+1))
else
	echo "2: Wrong number of subfolders!"
fi

# 3 Folder names
re='^[a-zA-Z]{1,7}$'
if [[ $3 =~ $re ]]; then
	check_counter=$((check_counter+1))
else
	echo "3: Wrong folder name pattern!"
fi

# 4 Number of files
re='^[0-9]+$'
if [[ $4 =~ $re ]]; then
	check_counter=$((check_counter+1))
else
	echo "4: Wrong number of files!"
fi

# 5 Filename pattern
re='^[a-zA-Z]{1,7}[.]{1}[a-zA-Z]{1,3}$'
if [[ $5 =~ $re ]]; then
	check_counter=$((check_counter+1))
else
	echo "5: Wrong file pattern"
fi

# 6 File size
re='^([1-9]|[0-9]{2}|100)kb$'
if [[ $6 =~ $re ]]; then
	check_counter=$((check_counter+1))
else
	echo "6: Wrong filesize (1-100kb)"
fi

