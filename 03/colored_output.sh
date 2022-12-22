#!/bin/bash

source colors.sh

#source output.sh | awk -F "=" '{printf "%s%s%s%s", ${fg_array[$1]}, $1, $off_color, $2}'
source output.sh | awk \
        -v off_col="$off_color"\
        -v fg_1="${fg_array[$1]}"\
        -v bg_1="${bg_array[$2]}"\
        -v fg_2="${fg_array[$3]}"\
        -v bg_2="${bg_array[$4]}"\
        -F "=" '{printf "%s%s%s%s=%s%s%s%s\n", fg_1, bg_1, $1, off_col, fg_2, bg_2, $2, off_col}'
