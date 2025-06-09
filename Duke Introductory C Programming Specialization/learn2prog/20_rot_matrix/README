For this problem, you will be writing a function which 
performs a 90 degree clockwise rotation of a 10x10 matrix.
There is nothing special about a 10x10 matrix---we are just
fixing the size so that you can read the input in a future
assignment after you have learned about reading files,
but before you have learned about dynamic memory allocation.

In particular, you should write

  void rotate(char matrix[10][10])

in a file called rotate.c

This function takes a 10 by 10 matrix of characters and rotates
it 90 degrees clockwise, updating the matrix that was passed in
(remember that arrays are pointers, so you will modify
the array in the frame where it was created).

As you have not yet learned to read from files, we have
provided a compiled object file, read-matrix.o.  This
object file has a main function which will read
the input file (specified as a command line arugments
to your program), call your rotate function, and
then print the result.

If you compiled your code (and linked with read-matrix.o)
into a program called rotate-matrix, you might run it as

./rotate-matrix sample.txt

It will then print the resulting matrix, which in this case
should look like the contents of the file sample.out.
(Remember that you can use > to redirect the output
of a program to a file, and use diff to compare
the contents of two files).

Note that you do not have to complete the rotation 'in place'.
