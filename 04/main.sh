#!/bin/bash

source colorscheme.conf

if [[ 1 -le $column1_background && $column1_background -le 6 ]]
then
	out1=$column1_background
else
	out1=7
fi
if [[ 1 -le $column1_font_color && $column1_font_color -le 6 ]]
then
	out2=$column1_font_color
else
	out2=7
fi
if [[ 1 -le $column2_background && $column2_background -le 6 ]]
then
	out3=$column2_background
else
	out3=7
fi
if [[ 1 -le $column2_font_color && $column2_font_color -le 6 ]]
then
	out4=$column2_font_color
else
	out4=7
fi
	source colored_output.sh
