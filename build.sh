#!/bin/bash
if [ "$1" = "1" ]; then
    rm src/matrix 2>/dev/null
    g++ src/a1.cpp -o src/matrix
elif [ "$1" = "2" ]; then
    rm src/dll 2>/dev/null
    g++ src/a2.cpp -o src/dll
elif [ "$1" = "3" ]; then
    rm src/smartpointer 2>/dev/null
    g++ src/a3.cpp -o src/smartpointer
else
    g++ src/a1.cpp -o src/matrix
    g++ src/a2.cpp -o src/dll
    g++ src/a3.cpp -o src/smartpointer
fi
