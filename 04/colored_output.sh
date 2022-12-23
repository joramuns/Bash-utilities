#!/bin/bash

source colors.conf

source output.sh | awk \
	-v off_col="$off_color"\
	-v bg_1="${bg_array[$out1]}"\
	-v fg_1="${fg_array[$out2]}"\
	-v bg_2="${bg_array[$out3]}"\
	-v fg_2="${fg_array[$out4]}"\
       	-F "=" '{printf "%s%s%s%s=%s%s%s%s\n", bg_1, fg_1, $1, off_col, bg_2, fg_2, $2, off_col}'
if [[ $out1 == $column1_background ]]
then
	numcolor1="default"
else
	numcolor1=$out1
fi
if [[ $out2 == $column1_font_color ]]
then
	numcolor2="default"
else
	numcolor2=$out2
fi
if [[ $out3 == $column2_background ]]
then
	numcolor3="default"
else
	numcolor3=$out3
fi
if [[ $out4 == $column2_font_color ]]
then
	numcolor4="default"
else
	numcolor4=$out4
fi
echo "Column 1 background = $numcolor1 (${word_array[$out1]})"
echo "Column 1 font color = $numcolor2 (${word_array[$out2]})"
echo "Column 2 background = $numcolor3 (${word_array[$out3]})"
echo "Column 2 font color = $numcolor4 (${word_array[$out4]})"
