#!/bin/bash

source data.sh

echo HOSTNAME=$(hostname)
echo TIMEZONE=$timezone
echo USER=$(whoami)
echo OS=$os_version
echo DATE=$time_now
echo UPTIME=$uptime_full
echo UPTIME_SEC=$uptime_seconds
echo IP=$ip_address
echo MASK=$netmask
echo GATEWAY=$gateway
echo RAM_TOTAL=$ram_total
echo RAM_USED=$ram_used
echo RAM_FREE=$ram_free
echo SPACE_ROOT=$root_total
echo SPACE_ROOT_USED=$root_used
echo SPACE_ROOT_FREE=$root_free
