CFLAGS=-ggdb3 -Wall -Werror -pedantic -std=gnu99
GIVEN_OBJS=deck.o  eval.o  future.o  input.o  main.o eval-c4.o deck-c4.o

test: cards.o my-test-main.o
	gcc -o test -ggdb3 cards.o my-test-main.o
poker: $(GIVEN_OBJS) cards.o
	gcc -o poker -ggdb3  cards.o $(GIVEN_OBJS)
clean:
	rm test poker cards.o my-test-main.o *~
