#!/bin/bash

# Set colors for output
source colors.conf

# Timer is ON
time_start=$(date +"%s.%N")

# Check input
if [ -d "$1" ]; then

# Get all data
	source properties.sh

# Output info
	source output.sh

# Timer is OFF
	time_end=$(date +"%s.%N")
	total_time=$(echo "$time_end - $time_start" | bc | awk '{printf "%.2f", $1}')
	echo -e ${green_color}"Script execution time (in seconds) = $total_time"${off_color}

# Clean trash
	sudo rm .temp .typetemp .sizetemp .execsizetemp .execmd5sum
else
# Throw error message
	echo -e ${red_color}"Wrong path!"${off_color}
fi
