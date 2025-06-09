#!/bin/bash
run_test(){
    prog="$1"
    testfile="$2"
    IFS=$'\n'
    for line in `cat $testfile`
    do
	IFS=" " correct=`/usr/local/l2p/match5/correct-match5 $line 2>&1`
	IFS=" " broken=`$prog $line 2>&1`
	if [ "$broken" != "$correct" ]
	then
	    return 0
	fi
    done
    return 1
}

found=0
notfound=0
for i in /usr/local/l2p/match5/match5-*
do
    run_test $i tests.txt
    x="$?"
    if [ "$x" != "0" ]
    then
	echo "Your test cases did not identify the problem with `basename $i`"
	let notfound=${notfound}+1
    else
	let found=${found}+1
    fi
done
echo "Test cases identified $found problems"
echo "Test cases failed to identify $notfound problems"
