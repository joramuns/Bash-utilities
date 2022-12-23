#!/bin/bash

source output.sh

echo "Save output to file? (Y/N)"
read answer
if [[ $answer =~ [Yy] ]]
then
        filename="$(date +"%d_%m_%y_%H_%M_%S").status"
        source output.sh > $filename
fi
