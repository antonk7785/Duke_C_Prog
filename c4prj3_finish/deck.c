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


void add_card_to(deck_t * deck, card_t c)
{
  card_t * ct = malloc(sizeof(* ct));

  ct->value = c.value; 
  ct->suit = c.suit;

  deck->cards = realloc(deck->cards, (deck->n_cards + 1) * sizeof(* deck->cards));
  deck->cards[deck->n_cards] = ct;
  deck->n_cards ++;
}

card_t * add_empty_card(deck_t * deck)
{
  card_t * ct = malloc(sizeof(* ct));

  ct->value = 0; 
  ct->suit = 0;

  deck->cards = realloc(deck->cards, (deck->n_cards + 1) * sizeof(* deck->cards));
  deck->cards[deck->n_cards] = ct;
  deck->n_cards ++;
  return ct;
}

deck_t * make_deck_exclude(deck_t * excluded_cards)
{

  deck_t * ans = malloc(sizeof(* ans));
  
  ans->cards = NULL;
  
  ans->n_cards = 0;
  
  for(unsigned i = 0;i < 52; i++)
  {  
    card_t c = card_from_num(i);
    
    if(!deck_contains(excluded_cards,c)) 
    {
      add_card_to(ans,c);
    }
  }
  
  return ans;
}

void free_deck(deck_t * deck)
{
 
  for(int i = 0; i < deck->n_cards; i++)
  {
    
    free(deck->cards[i]);
    
  }
  
  free(deck->cards);
  
  free(deck);
}

deck_t * build_remaining_deck(deck_t ** hands, size_t n_hands)
{  
  deck_t * deck = malloc(sizeof(*deck));
  
  deck->n_cards = 0;
  
  deck->cards = NULL;
  
  for (size_t i = 0 ; i < n_hands ; i++)
  {
    
    for(int j = 0 ; j < hands[i]->n_cards; j++)
    {
      
      deck->cards = realloc(deck->cards, (deck->n_cards + 1) * sizeof(* deck->cards));
      
      deck->cards[deck->n_cards] = hands[i]->cards[j];
      
      deck->n_cards ++;
      
    }
    
  }
  
  deck_t * deck1 = make_deck_exclude(deck);
  
  free(deck->cards);
  
  free(deck);
  
  return deck1;
}
