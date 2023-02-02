#!/bin/bash

source data.sh

function get_line () {
    echo -n "$(get_ip) "
    echo -n "- "
    echo -n "- "
    echo -n "[$(clf_date ${sorted_datetime_array[$m_i]})] "
    echo -n "\"$(get_method)\" "
    echo -n "$(get_response) "
    echo -n "$(get_random 1 5000) "
    echo -n "\"url.com\" "
    echo "\"$(get_agent)\""
}
