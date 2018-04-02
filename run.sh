#!/bin/bash
if [ "$1" = "1" ]; then
    src/matrix
elif [ "$1" = "2" ]; then
    src/dll
elif [ "$1" = "3" ]; then
    src/smartpointer
else
    echo Error: accepted arguments are "1" "2" "3"
    false
fi
