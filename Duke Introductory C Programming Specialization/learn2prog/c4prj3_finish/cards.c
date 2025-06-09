#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(c.value >= 2 && c.value <= VALUE_ACE);
  assert(c.suit >= SPADES && c.suit < NUM_SUITS);
}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r) {
  case STRAIGHT_FLUSH:
    return "STRAIGHT_FLUSH";
  case FOUR_OF_A_KIND:
    return "FOUR_OF_A_KIND";
  case FULL_HOUSE:
    return "FULL_HOUSE";
  case FLUSH:
    return "FLUSH";
  case STRAIGHT:
    return "STRAIGHT";
  case THREE_OF_A_KIND:
    return "THREE_OF_A_KIND";
  case TWO_PAIR:
    return "TWO_PAIR";
  case PAIR:
    return "PAIR";
  default:
    return "NOTHING";
  }
}

char value_letter(card_t c) {
  unsigned value = c.value;
  if (value <= 9) {
    return '0' + value;
  } else {
    char ch[5] = {'0', 'J', 'Q', 'K', 'A'};
    return ch[value - 10];
  }
}


char suit_letter(card_t c) {
  char ch[4] = {'s', 'h', 'd', 'c'};
  return ch[c.suit];
}

void print_card(card_t c) {
  printf("%c%c", value_letter(c), suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let) {
  assert((value_let >= '0' && value_let <= '9' && value_let != '1') || value_let == 'A' || value_let == 'K' || value_let == 'Q' || value_let == 'J' );
  assert(suit_let == 's' || suit_let == 'h' || suit_let == 'd' ||suit_let == 'c');
  card_t temp;
  switch(value_let) {
  case 'A':
    temp.value = VALUE_ACE;break;
  case 'K':
    temp.value = VALUE_KING;break;
  case 'Q':
    temp.value = VALUE_QUEEN;break;
  case 'J':
    temp.value = VALUE_JACK;break;
  case '0':
    temp.value = 10;break;
  default:
    temp.value = value_let - '0';
  }
  switch(suit_let) {
  case 's': temp.suit = SPADES;break;
  case 'h': temp.suit = HEARTS;break;
  case 'd': temp.suit = DIAMONDS;break;
  case 'c': temp.suit = CLUBS; break;
  }
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  temp.value = c % 13 + 2;
  temp.suit = (suit_t)(c / 13);
  return temp;
}