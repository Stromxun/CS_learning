#!/bin/bash

for i in /usr/local/l2p/subseq/subseq*.o
do
    test=`basename $i | sed 's/subseq//' | sed 's/.o//'`
    if [ "$test"  == "" ]
    then
	echo "**Testing correct implementation **"
    else
	echo "**Testing broken implementation ${test} **"
    fi
    echo "-------------------------------------"
    echo ""

    gcc -o test-subseq test-subseq.c $i
    if [ "$?" != "0" ]
    then
	echo "Could not compile test-subseq.c with $i" > /dev/stderr
	exit 1
    fi
    ./test-subseq
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
