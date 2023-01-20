#!/bin/bash

off_color="\033[0m"
fg_white="\033[97m"
fg_red="\033[31m"
fg_green="\033[32m"
fg_blue="\033[34m"
fg_purple="\033[35m"
fg_black="\033[30m"
bg_white="\033[107m"
bg_red="\033[41m"
bg_green="\033[42m"
bg_blue="\033[44m"
bg_purple="\033[45m"
bg_black="\033[30m"

declare -A fg_array
fg_array[1]=$fg_white
fg_array[2]=$fg_red
fg_array[3]=$fg_green
fg_array[4]=$fg_blue
fg_array[5]=$fg_purple
fg_array[6]=$fg_black

declare -A bg_array
bg_array[1]=$bg_white
bg_array[2]=$bg_red
bg_array[3]=$bg_green
bg_array[4]=$bg_blue
bg_array[5]=$bg_purple
bg_array[6]=$bg_black
