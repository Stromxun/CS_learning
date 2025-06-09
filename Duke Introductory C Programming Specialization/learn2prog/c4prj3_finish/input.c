#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

deck_t * hand_from_string(const char * str, future_cards_t * fc) {
    size_t n = strlen(str);
    int i = 0;
    deck_t* tmp = malloc(sizeof(*tmp));
    tmp->cards = NULL;
    tmp->n_cards = 0;
    while(i < n) {
        if (str[i] != '\n' && str[i] != ' ') {
            if (str[i] == '?') {
                // empty card;
                int j = i + 1, num = 0;
                while (j < n) {
                    if (str[j] == '\n' || str[j] == ' ') {
                        break;
                    }
                    num = num * 10 + (str[j] - '0');
                    j++;
                }
                i = j;
                add_future_card(fc, num, add_empty_card(tmp));
            } else {
                // actual card;
                card_t c = card_from_letters(str[i], str[i + 1]);
                add_card_to(tmp, c);
                i++;
            }
        }
        i++;
    }
    if (tmp->n_cards < 5) {
        free_deck(tmp);
        return NULL;
    }
    return tmp;  
}

deck_t ** read_input(FILE * f, size_t * n_hands, future_cards_t * fc) {
    deck_t ** hands = NULL;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, f)) != -1) {
        deck_t * tmp = hand_from_string(line, fc);
        if (tmp == NULL) {
            perror("the hand only less 5 cards");
            return NULL;
        }
        *n_hands += 1;
        deck_t ** h = realloc(hands, *n_hands * sizeof(*h));
        hands = h;
        hands[(*n_hands) - 1] = tmp;
        free(line);
        line = NULL;
    }
    free(line);
    return hands;
}
