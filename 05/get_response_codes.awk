#!/usr/bin/awk -f

 {
    codes[$6]++
    }
    END {
        for (code in codes) {
            print code
            }
        }
