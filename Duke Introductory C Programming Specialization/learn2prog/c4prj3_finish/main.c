#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "cards.h"
#include "deck.h"
#include "eval.h"
#include "future.h"
#include "input.h"



int main(int argc, char ** argv) {
  //YOUR CODE GOES HERE
  if (argc == 1 || argc > 3) {
    perror("Usage: poker <filename> <trials count:default(10000)>");
    return EXIT_FAILURE;
  }
  FILE* f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("Could not open the file");
    return EXIT_FAILURE;
  }
  
  int trials = (argc == 3 ? atoi(argv[2]) : 10000);
  
  size_t n_hands = 0;
  future_cards_t * fc = malloc(sizeof(*fc));
  fc->n_decks = 0;
  fc->decks = NULL;
  deck_t ** hands = read_input(f, &n_hands, fc);
  deck_t * deck = build_remaining_deck(hands, n_hands);

  // index n_hands is tie
  int win[n_hands + 1];
  for (int i = 0; i <= n_hands; i++) win[i] = 0;

  // Monte Carlo trial
  for (int i = 0; i < trials; i++) {
    shuffle(deck);
    future_cards_from_deck(deck, fc);
    int is_tie = 1;
    int winner = 0;
    for (int i = 1; i < n_hands; i++) {
        int result = compare_hands(hands[winner], hands[i]);
        if (is_tie && result) is_tie = 0;
        if (result < 0) {
            winner = i;
        }  
    }
    if (is_tie == 1) {
        winner = n_hands;
    }
    win[winner]++;
  }
  for (size_t i = 0; i < n_hands; i++) {
    printf("Hand %zu won %u / %u times (%.2f%%)\n", i, win[i], trials, 100.0 * win[i] / trials);
  }
  printf("And there were %u ties\n", win[n_hands]);

  // free allocate memory
  for (int i = 0; i < n_hands; i++) free_deck(hands[i]);
  free(hands);
  for(int i = 0; i < fc->n_decks; i++){
    free_deck(&fc->decks[i]);
  }
  free(fc);
  free(fc);
  free_deck(deck);
  fclose(f);
  return EXIT_SUCCESS;
}