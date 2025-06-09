#!/bin/bash

for i in /usr/local/l2p/power/power*.o
do
    test=`basename $i | sed 's/power//' | sed 's/.o//'`
    if [ "$test"  == "" ]
    then
	echo "**Testing correct implementation **"
    else
	echo "**Testing broken implementation ${test} **"
    fi
    echo "-------------------------------------"
    echo ""
    gcc -o test-power test-power.c $i
    if [ "$?" != "0" ]
    then
	echo "Could not compile test-power.c with $i" > /dev/stderr
	exit 1
    fi
    ./test-power
    if [ "$?" != 0 ]
    then
	if [ "$test" == "" ]
	then
	    echo "Your test program falsely failed the correct implementation!" > /dev/stderr
	    exit 1
	fi
    else
	if [ "$test" != "" ]
	then
	    echo "Your test program did not identify $i as broken!" > /dev/stderr
	    exit 1
	fi
    fi
    echo ""
done
