#!/bin/bash

source colors.sh

source output.sh | awk \
	-v off_col="$off_color"\
	-v bg_1="${bg_array[$1]}"\
	-v fg_1="${fg_array[$2]}"\
	-v bg_2="${bg_array[$3]}"\
	-v fg_2="${fg_array[$4]}"\
       	-F "=" '{printf "%s%s%s%s=%s%s%s%s\n", bg_1, fg_1, $1, off_col, bg_2, fg_2, $2, off_col}'
