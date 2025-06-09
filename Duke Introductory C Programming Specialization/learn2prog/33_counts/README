 For this problem, we will address the following tasks:

 - print the counts to a file
 - free the memory for the counts

We'll note that we are not going to write the part of this program where
we read the input file and compute the counts until the next problem.  However, we will
still want to be able to test our code.   We can do this, by having a main
function which constructs the counts from a hard coded set of data, skipping
the details of the actual program (this is an example of a test scaffold).

Our test scaffold can benefit from some functionality that (if we think a bit ahead)
will be useful to abstract out into a couple functions, so we can re-use that code
in the next problem.  (Abstracting all of this code out into function is also good because
it hides the implementation details: none of the code in the main function
we provide cares what the names/types of the fields in the counts_t structure
are, which you will make shortly).

First, go to counts.h. Here, you will find two empty struct declarations.  You will
need to fill these in.  The first should reflect the information about one count.
That is, for some particular string, how many times have we seen it so far.
The second, should have an array of the first, as well as the size of that array.
You should also include a field in this struct to count unknown names.

Next, you should go to counts.c, and write the four functions there.

The first, createCounts should allocate memory for a counts_t structure, and initialize
it to represent that nothing has been counted yet.

The next function, addCount, should increment the count for the corresponding name.  Note
that name will be NULL in the case of something that is unknown, so your code must account
for this case.   

The third function, printCounts takes a counts_t and prints that information to 
the FILE outFile. Recall from the description of the entire problem, that this 
function should print in the format:

Captain: 1
Commander: 2
Lt. Commander: 1
<unknown> : 1

These should appear in the order that the name is first added, with unknown always
appearing last.

***If there are no unknown values, you should not print a line for unknown.  That
is, you should NEVEr print
<unknown> : 0


Finally, you should write freeCounts, which should free all the memory associated with
a counts_t.  

We have provided a main in countsTestc which creates a counts_t (using your createCounts
function), adds some names to it (using your addCount function), prints the result
to stdout (using your printCounts) function, then frees the memory (using your freeCounts).

Test and debug these functions before proceeding.
