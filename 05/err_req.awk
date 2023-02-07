#!/usr/bin/awk -f

{
    if ($7 ~ "^[45]..") 
    {
        print $0
    }
}
