#!/bin/bash

source colorscheme.conf

if [[ ($1 != [1-6]) ]]
then
	out1=$column1_background
else
	out1=$1
fi
if [[ ($2 != [1-6]) ]]
then
	out2=$column1_font_color
else
	out2=$2
fi
if [[ ($3 != [1-6]) ]]
then
	out3=$column2_background
else
	out3=$3
fi
if [[ ($4 != [1-6]) ]]
then
	out4=$column2_font_color
else
	out4=$4
fi
	source colored_output.sh
