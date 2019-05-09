#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"

void assert_card_valid(card_t c) {

  assert((c.suit < NUM_SUITS) && (c.value >= 2 && c.value <= 14));

}

const char * ranking_to_string(hand_ranking_t r) 
{
 
  switch (r)
  {
    case 0:
      return "STRAIGHT_FLUSH";
      break;
    case 1:
      return "FOUR_OF_A_KIND";
      break;
    case 2:
      return "FULL_HOUSE";
      break;
    case 3:
      return "FLUSH";
      break;
    case 4:
      return "STRAIGHT";
      break;
    case 5:
      return "THREE_OF_A_KIND"; 
      break;
    case 6:
      return "TWO_PAIR"; 
      break;
    case 7:
      return "PAIR"; 
      break;
    case 8:
      return "NOTHING"; 
      break; 
    default:
      exit(EXIT_FAILURE);
      break;
  }
}

char value_letter(card_t c) 
{
  
    if (c.value >= 2 && c.value < 10)
    {     
      return c.value + 48;
    }
    else
    {
      switch (c.value)
      { 
        case 10:
          return '0';
          break;
        case 11:
          return 'J';
          break;
        case 12:
          return 'Q';
          break;
        case 13:
          return 'K';
          break;
        case 14:
          return 'A';
          break;
        default:
          exit(EXIT_FAILURE);
      }
    }
  
}


char suit_letter(card_t c) 
{
  
  switch (c.suit)
  {
  case 0:  
    return 's';
    break;
  case 1:  
    return 'h';
    break;
  case 2:  
    return 'd';
    break;
  case 3:  
    return 'c';
    break;
  default:  
    exit(EXIT_FAILURE);
  }
}

void print_card(card_t c) {
  
  printf("%c%c",value_letter(c),suit_letter(c));

}

card_t card_from_letters(char value_let, char suit_let) {
  
  card_t temp;
  
  if (((value_let >= 50 && value_let <= 57) || value_let == 48 || value_let == 65 || value_let == 74 || value_let == 75 || value_let == 81) && (suit_let == 99 || suit_let == 100 || suit_let == 104 || suit_let == 115))
  {
    if (value_let >= 50 && value_let <= 57)
    { 
      temp.value = value_let - 48;
    }  
    else
    {
      switch (value_let)
      {
        case 48:
          temp.value = 10;
          break;
        case 65:
          temp.value = 14;
          break;
        case 74:
          temp.value = 11;
          break;
        case 75:
          temp.value = 13;
          break;
        case 81:
          temp.value = 12;
          break;
      }
    }

    switch (suit_let)
    {
      case 99:
        temp.suit = 3;
        break;
      case 100:
        temp.suit = 2;
        break;
      case 104:
        temp.suit = 1;
        break;
      case 115:
        temp.suit = 0;
        break;
      
    }
    return temp;
  }
  else  
    exit(EXIT_FAILURE);

}

card_t card_from_num(unsigned c) {
  
  card_t temp;
  
  if ( c >= 0 && c <= 52)
  {
    temp.value = (c % 13) + 2;
    temp.suit = (c % 4);  
    return temp;
  }
  else 
    exit(EXIT_FAILURE);
}
