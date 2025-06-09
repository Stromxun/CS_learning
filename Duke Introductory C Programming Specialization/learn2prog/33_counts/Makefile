CFLAGS=-Wall -Werror -std=gnu99 -pedantic -ggdb3
OBJS=counts.o counts_test.o
PROGRAM=counts_test

$(PROGRAM): $(OBJS)
	gcc $(CFLAGS) -o $@ $(OBJS)

%.o: %.c counts.h
	gcc -c $(CFLAGS) $<

clean:
	rm -f $(OBJS) $(PROGRAM) *~