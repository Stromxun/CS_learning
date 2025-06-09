#!/bin/bash
cat > temp.c <<EOF
#include <stdio.h>
#include <stdlib.h>
EOF
cat code2.c >> temp.c
gcc -Wall -Werror -pedantic -std=gnu99 temp.c -o code2 2>errors.txt
if [ "$?" = "0" ]
    then
    echo "Your code appears to have legal syntax!"
    echo "Here is what I get when I run it..."
    echo "-----------------"
    ./code2
    echo "-----------------"
    echo "Here is what I would expect the answers to be:"
    echo "----------------"
    cat <<EOF 
Here is a triangle with height 4
*
**
***
****
That triangle had 10 total stars
Here is a triangle with height 7
*
**
***
****
*****
******
*******
That triangle had 28 total stars
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
rm -f errors.txt temp.c code2

