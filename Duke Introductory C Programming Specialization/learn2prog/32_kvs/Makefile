CFLAGS=-Wall -Werror -std=gnu99 -pedantic -ggdb3
OBJS=kv_test.o kv.o
PROGRAM=kv_test

$(PROGRAM): $(OBJS)
	gcc $(CFLAGS) -o $@ $(OBJS)

%.o: %.c kv.h
	gcc -c $(CFLAGS) $<

clean:
	rm -f $(OBJS) $(PROGRAM) *~