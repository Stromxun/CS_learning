#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
void print_hand(deck_t * hand){
  int n = hand->n_cards;
  for (int i = 0; i < n; i++) {
    print_card(*(hand->cards[i]));
    printf(" ");
  }
}

int deck_contains(deck_t * d, card_t c) {
  int n = d->n_cards;
  for (int i = 0; i < n; i++) {
    if (d->cards[i]->suit == c.suit && d->cards[i]->value == c.value) {
      return 1;
    }
  }
  return 0;
}

void shuffle(deck_t * d){
  int n = d->n_cards;
  for (int i = 0; i < n; i++) {
    int r = random() % n;
    // swap
    card_t* temp = d->cards[i];
    d->cards[i] = d->cards[r];
    d->cards[r] = temp;
  }
}



void assert_full_deck(deck_t * d) {
  assert(d->n_cards <= 52 && d->n_cards > 0);
  for (int i = 2; i <= 14; i++) {
    for (int j = 0; j < 4; j++) {
      card_t card = {i, j};
      assert(deck_contains(d, card));
    }
  }
}
