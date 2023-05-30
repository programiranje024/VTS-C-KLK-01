#!/bin/bash
# Check if gcc is installed
if [ -x "$(which gcc)" ] ; then
    echo "Cleaning..."
    rm -rf out/
    mkdir out/
    echo "Compiling..."
    gcc -o out/vts main.c
else
    echo "please install gcc"
    exit 1
fi