#!/bin/bash

check_counter=0

# 1 Folder names
re='^[a-zA-Z]{1,7}$'
if [[ $1 =~ $re ]]; then
	check_counter=$((check_counter+1))
else
	echo "3: Wrong folder name pattern!"
fi

# 2 Filename pattern
re='^[a-zA-Z]{1,7}[.]{1}[a-zA-Z]{1,3}$'
if [[ $2 =~ $re ]]; then
	check_counter=$((check_counter+1))
else
	echo "5: Wrong file pattern"
fi

# 3 File size
re='^([1-9]|[0-9]{2}|100)Mb$'
if [[ $3 =~ $re ]]; then
	check_counter=$((check_counter+1))
else
	echo "6: Wrong filesize (1-100Mb)"
fi

