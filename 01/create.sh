#!/bin/bash

function create_file () {
    fallocate -l $1K $2
}
