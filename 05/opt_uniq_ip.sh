#!/bin/bash

files=$(find . -name "*.log")

./uniq_ip.awk $files
