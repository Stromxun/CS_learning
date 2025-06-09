#include "future.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_future_card(future_cards_t * fc, size_t index, card_t * ptr) {
    if (fc->n_decks <= index) { // expand the decks
        int n = index + 1;
        deck_t* tmp = realloc(fc->decks, (n) * sizeof(*tmp));
        fc->decks = tmp;
        for (int i = fc->n_decks; i < n; i++) {
            fc->decks[i].cards = NULL;
            fc->decks[i].n_cards = 0;
        }
        fc->n_decks = n;
    }
    // realloc
    int cn = fc->decks[index].n_cards + 1;
    card_t** t = realloc(fc->decks[index].cards, cn * sizeof(*t));
    fc->decks[index].cards = t;

    fc->decks[index].cards[cn - 1] = ptr;
    fc->decks[index].n_cards = cn;
}

void future_cards_from_deck(deck_t * deck, future_cards_t * fc) {
    if (deck == NULL || fc == NULL) {
        perror("Invalid input pointers");
        return;
    }
    int dn = deck->n_cards, fn = fc->n_decks;
    if (fn > dn) {
        perror("the cards in deck can't fill over these placeholders");
        return;
    }
    for (int i = 0; i < fn; i++) {
        for (int j = 0; j < fc->decks[i].n_cards; j++) {
            fc->decks[i].cards[j]->suit = deck->cards[i]->suit;
            fc->decks[i].cards[j]->value = deck->cards[i]->value;
        }
    }
}
