#ifndef CARD_H
#define CARD_H
#define VALUE_ACE 14
#define VALUE_KING 13
#define VALUE_QUEEN 12
#define VALUE_JACK 11
typedef enum {
  SPADES,
  HEARTS,
  DIAMONDS,
  CLUBS,
  NUM_SUITS
} suit_t;

struct card_tag {
  unsigned value;
  suit_t suit;
};
typedef struct card_tag card_t;
typedef enum {
  STRAIGHT_FLUSH,
  FOUR_OF_A_KIND,
  FULL_HOUSE,
  FLUSH,
  STRAIGHT,
  THREE_OF_A_KIND,
  TWO_PAIR,
  PAIR,
  NOTHING
} hand_ranking_t;
card_t card_from_num(unsigned c);
void assert_card_valid(card_t c);
const char * ranking_to_string(hand_ranking_t r) ;
char value_letter(card_t c);
char suit_letter(card_t c) ;
void print_card(card_t c);
card_t card_from_letters(char value_let, char suit_let);
#endif
