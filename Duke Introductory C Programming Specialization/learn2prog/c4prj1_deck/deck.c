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

void add_card_to(deck_t * deck, card_t c) {
  // expand the array
  deck->n_cards += 1;
  card_t** tmp = realloc(deck->cards, (deck->n_cards) * sizeof(*tmp));
  deck->cards = tmp;
  
  card_t * t = malloc(sizeof(*t));
  t->suit = c.suit, t->value = c.value;
  deck->cards[deck->n_cards - 1] = t;
}

card_t * add_empty_card(deck_t * deck) {
  card_t empty;
  empty.suit = 0, empty.value = 0;
  add_card_to(deck, empty);
  return deck->cards[deck->n_cards - 1];
}

deck_t * make_deck_exclude(deck_t * excluded_cards) {
  deck_t * d = malloc(sizeof(*d));
  d->cards = NULL;
  d->n_cards = 0;
  for (int i = 0; i < 52; i++) {
    card_t c = card_from_num(i);
    if (!deck_contains(excluded_cards, c)) {
      add_card_to(d, c);
    }
  }
  return d;
}

deck_t * build_remaining_deck(deck_t ** hands, size_t n_hands) {
  deck_t * t = malloc(sizeof(*t));
  t->cards = NULL;
  t->n_cards = 0;
  for (int i = 0; i < n_hands; i++) {
    int n = hands[i]->n_cards;
    for (int j = 0; j < n; j++) {
      card_t c = *(hands[i]->cards[j]);
      if (!deck_contains(t, c)) {
        add_card_to(t, c);
      }
    }
  }
  deck_t * ans = make_deck_exclude(t);
  free_deck(t);
  return ans;
}

void free_deck(deck_t * deck) {
  int n = deck->n_cards;
  for (int i = 0; i < n; i++) {
    free(deck->cards[i]);
  }
  free(deck);
}
