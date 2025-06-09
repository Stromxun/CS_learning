#ifndef FUTURE_H
#define FUTURE_H
#include "deck.h"


struct future_cards_tag {
  deck_t * decks;
  size_t n_decks;
};
typedef struct future_cards_tag future_cards_t;
void add_future_card(future_cards_t * fc, size_t index, card_t * ptr) ;
void future_cards_from_deck(deck_t * deck, future_cards_t * fc);


#endif 
