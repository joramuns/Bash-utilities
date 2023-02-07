#!/usr/bin/awk -f

{
    if ($6 ~ "^[45]..") 
    {
        print $0
    }
}
