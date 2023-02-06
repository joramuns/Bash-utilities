#!/usr/bin/awk -f

{
    counter[$1]++
    }
    END {
        for (line in counter) {
            if (counter[line] == 1) {
                print line
                }
            }
        }
