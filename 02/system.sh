#!/bin/bash

hostname=$(hostname)
timezone=$(cat /etc/timezone) + $(date +%z | awk '{printf "UTC +%d", $1/100}')

echo "$hostname"
echo $timezone

