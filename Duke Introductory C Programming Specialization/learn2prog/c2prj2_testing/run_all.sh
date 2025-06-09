#!/bin/bash
run_test(){
    prog="$1"
    testfile="$2"
    IFS=$'\n'
    IFS=" " correct=`/usr/local/l2p/poker/correct-test-eval $testfile 2>&1`
    IFS=" " broken=`$prog $testfile 2>&1`
    if [ "$broken" != "$correct" ]
    then
	return 0
    fi
    return 1
}

found=0
notfound=0
for i in /usr/local/l2p/poker/test-eval-*
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
