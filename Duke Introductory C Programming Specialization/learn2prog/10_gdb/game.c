#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
int getSecretNumber(void); //prototype, implemented elsewhere.

int getOtherSN(int which); //prototype, implemented elsewhere.

int main(void) {
  int guessesMade = 0;
  int yourGuess;
  char buffer[1024];
  int myNumber = getSecretNumber();

  printf("I'm thinking of a number...\n");
  printf("What number do you guess?\n");
  if(fgets(buffer, 1024, stdin) == NULL) {
    printf("Oh no, you are giving up?  You lose...\n");
    return EXIT_FAILURE;
  }
  yourGuess = atoi(buffer);
  if(yourGuess != myNumber) {
    printf("I'm sorry, that is not right.  You lose\n");
    return EXIT_FAILURE;
  }
  printf("Correct! You win round1!\n");
  
  int total = 0;
  for (int i = 0; i <= 5678; i++) {
    total = total ^ getOtherSN(i);
  }
  printf("Ok, time for round 2. I have another secret number.\n");
  printf("Your guess:\n");
  if(fgets(buffer, 1024, stdin) == NULL) {
    printf("Oh no, you are giving up?  You lose...\n");
    return EXIT_FAILURE;
  }
  yourGuess = atoi(buffer);
  if (yourGuess == total) {
    printf("You win round 2 also!\n");
    return EXIT_SUCCESS;
  }
  printf("Sorry, you did not win the second round\n");
  return EXIT_FAILURE;
}
