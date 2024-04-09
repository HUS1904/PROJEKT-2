#include <stdlib.h>
#include <stdio.h>
#include "Shuffle.h"

const char* shuffle(Card** deck) {
    int deckLength;
    Card* previous = NULL;

    while (true) {
        deckLength = length(*deck);
        if(deckLength < 3)
            break;
        printf("Card has %i cards\n", deckLength);

        int r = rand() % deckLength;
        Card* current = malloc(sizeof(Card));
        *current = buildCard(get(*deck, r)->name);

        if (!current->precedence)
            continue;
        printf("Extracting %s\n", get(*deck, r)->name);
        linkCards(previous, current);
        previous = current;
        printf("Removing %s\n", get(*deck, r)->name);
        removeCard(get(*deck, r));
        printf("Removed card, new card at index %i is %s\n", r, get(*deck, r)->name);
    }
    linkCards(previous, *deck);
    *deck = first(previous);

    return "OK";
}