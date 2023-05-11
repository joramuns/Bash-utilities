#!/usr/bin/awk -f

{
    counter[$1]++
    }
    END {
        for (line in counter) {
            print line
            }
        }
