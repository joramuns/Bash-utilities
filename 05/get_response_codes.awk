#!/usr/bin/awk -f

 {
    codes[$7]++
    }
    END {
        for (code in codes) {
            print code
            }
        }
