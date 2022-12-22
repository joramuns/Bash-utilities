#!/bin/bash

if [[ ($# -ne 4) || !($1 =~ ^[1-6]$) || !($2 =~ ^[1-6]$) || !($3 =~ ^[1-6]$) || !($4 =~ ^[1-6]$) || ($1 == $2) || ($3 == $4) ]]
then
        echo "Incorrect color info"
else
        source colored_output.sh
fi
