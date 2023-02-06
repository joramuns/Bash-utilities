#!/bin/bash

files=$(find . -name "*.log")

./err_req.awk $files
