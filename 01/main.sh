#!/bin/bash

re="[0-9]"

if [ $# -ne 1 ]
then
  echo "Invalid input";
elif [[ $1 =~ $re ]]
then
  echo "Do not input numbers!";
else
  echo "$1";
fi
