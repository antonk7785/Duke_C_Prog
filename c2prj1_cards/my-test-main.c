#include "cards.h"
#include <stdio.h>

int main(void) 
{
  card_t card;
  card = card_from_num(50);
  print_card(card);
  return 0;
}
