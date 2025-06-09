#ifndef EVAL_H
#define EVAL_H
#include "deck.h"
struct hand_eval_tag {
  hand_ranking_t ranking;
  card_t *cards[5];
};
typedef struct hand_eval_tag hand_eval_t;

hand_eval_t evaluate_hand(deck_t * hand) ;
int compare_hands(deck_t * hand1, deck_t * hand2) ;

#endif
