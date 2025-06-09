#!/bin/bash
cat > temp.c <<EOF
#include <stdio.h>
#include <stdlib.h>
EOF
cat code1.c >> temp.c
gcc -Wall -Werror -pedantic -std=gnu99 temp.c -o code1 2>errors.txt
if [ "$?" = "0" ]
    then
    echo "Your code appears to have legal syntax!"
    echo "Here is what I get when I run it..."
    echo "-----------------"
    ./code1
    echo "-----------------"
    echo "Here is what I would expect the answers to be:"
    echo "----------------"
    cat <<EOF 
max(42,-69) is 42
max(33,0) is 33
max(0x123456,123456) is 1193046
max(0x451215AF, 0x913591AF) is 1158813103
EOF
    echo "---------------"
    else
    echo "Oh no, the syntax of your code is not correct!"
    mesg=`grep error errors.txt | head -1`
    ln=`echo "$mesg" | cut -f2 -d":"`
    let ln=${ln}-2
    echo "I discovered the problem on line $ln "
    echo "(though the problem may be earlier and I just got confused)"
    echo "Here is my best attempt to describe what is wrong:"
    echo "$mesg" | cut -f5 -d":"
    fi
rm -f temp.c errors.txt code1
