/*

struct deck_tag {
  card_t ** cards;
  size_t n_cards;
};
typedef struct deck_tag deck_t;




You'll write four functions in deck.c:

 - void print_hand(deck_t * hand);
   This should print out the contents of a hand.
   It should print each card (recall that
   you wrote print_card in Course 2), and
   a space after each card.  Do not put
   a newline after the hand, as this
   function gets called to print a hand
   in the middle of a line of output.


 - int deck_contains(deck_t * d, card_t c);
   This function should check if a deck
   contains a particular card or not.  If
   the deck does contain the card, this
   function should return 1.  Otherwise,
   it should return 0.
   (You will use this later to
   build the deck of remaining cards
   which are not in any player's hand).

 - void shuffle(deck_t * d);
   This function takes in a deck an shuffles
   it, randomly permuting the order of the cards.
   There are MANY valid ways to shuffle a deck
   of cards---we'll leave the specifics
   of the algorithm design up to you.  However,
   you will want to use random() to generate
   pseudo-random numbers.  (Pseudo-random
   numbers are quite sufficient here,
   since they are not used for security
   purposes).

   We will note that in trying to devise
   this algorithm, you should not
   try to shuffle a deck of cards "normally".
   Instead, you should take a small number
   of cards, and think about ways
   to shuffle them that involve using
   random numbers to swap their order,
   or pick positions for them, or
   similar principles.

- void assert_full_deck(deck_t * d);
  This function should check that
  the passed in deck contains ever
  valid card exactly once.  If
  the deck has any problems, this function
  should fail an assert.  This will
  be used to help you test your deck
  shuffling: we will shuffle
  a full deck, then call assert_full_deck,
  so that you can identfiy problems with
  the deck.  You can print
  any error messages you want
  if there is a problem.
  Hint: you already wrote deck_contains.

*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

void print_hand(deck_t * hand)
{
  for (int i = 0; i < hand->n_cards; i++)
  {
    print_card(* hand->cards[i]);
    printf(" ");
  }
}

int deck_contains(deck_t * d, card_t c) 
{
  for (int i = 0; i < d->n_cards; i++)
  {
    if (d->cards[i]->value == c.value && d->cards[i]->suit == c.suit)
      return 1;
  }
  return 0;
}

void shuffle(deck_t * d)
{
  int rd = 0;
  card_t *temp;  

  for (int i = 0; i < d->n_cards; i++)
  {
    rd = random() % (d->n_cards);
    temp = d->cards[i];
    d->cards[i] = d->cards[rd];
    d->cards[rd] = temp;
  }
}

void assert_full_deck(deck_t * d) 
{
  assert(d->n_cards == 52 && "Invalid number of cards");
  
  for (int i = 0; i < d->n_cards; i++)
  {
    assert(deck_contains(d, card_from_num(i)) && "Deck is invalid");
  }
}
