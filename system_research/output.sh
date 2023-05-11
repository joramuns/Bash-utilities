#!/bin/bash

source data.sh

echo -e HOSTNAME=$(hostname)
echo -e TIMEZONE=$timezone
echo -e USER=$(whoami)
echo -e OS=$os_version
echo -e DATE=$time_now
echo -e UPTIME=$uptime_full
echo -e UPTIME_SEC=$uptime_seconds
echo -e IP=$ip_address
echo -e MASK=$netmask
echo -e GATEWAY=$gateway
echo -e RAM_TOTAL=$ram_total
echo -e RAM_USED=$ram_used
echo -e RAM_FREE=$ram_free
echo -e SPACE_ROOT=$root_total
echo -e SPACE_ROOT_USED=$root_used
echo -e SPACE_ROOT_FREE=$root_free
