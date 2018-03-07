#!/bin/bash
if [ "$1" = "1" ]; then
    src/matrix
elif [ "$1" = "2" ]; then
    src/dll
else
    echo Error: accepted arguments are "1" "2"
    false
fi
