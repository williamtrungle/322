#!/bin/bash
if [ "$1" = "1" ]; then
    rm src/matrix 2>/dev/null
    g++ src/a1.cpp -o src/matrix
elif [ "$1" = "2" ]; then
    rm src/dll 2>/dev/null
    g++ src/a2.cpp -o src/dll
else
    echo Error: accepted arguments are "1" "2"
    false
fi
