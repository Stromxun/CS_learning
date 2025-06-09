#!/bin/bash
run_test() {
    prog="$1"
    testfile="$2"
    IFS=$'\n'
    for line in `cat $testfile | sed 's/^$/ /'`
    do
	IFS=" " correct=`/usr/local/l2p/rot_matrix/rotateMatrix $line 2>&1`
	IFS=" " broken=`$prog $line 2>&1`
	if [ "$broken" != "$correct" ]
	then
	    return 0
	fi
    done
    return 1
}

for i in /usr/local/l2p/rot_matrix/rotateMatrix*
do
    if [ "$i" != "/usr/local/l2p/rot_matrix/rotateMatrix" ]
       then
	   echo "Checking `basename $i`"
	   run_test $i tests.txt
	   x="$?"
	   if [ "$x" != "0" ]
	   then
	       echo "***Your tests failed to show that `basename $i` was broken!"
	   fi
    fi
done
