//Card interface file
#ifndef __CARD_H__
#define __CARD_H__

#include <iostream>

using namespace std;

class Card {
 private:
    char suit;
    int rank;
 public:
 
    /* Assigns a default value of 2 of Clubs
    */
    Card();


    /* Assigns the Card the suit and rank provided.
       suits: c = Clubs, d = Diamonds, h = Hearts, s = Spades
       If an invalid suit is provided, sets the suit to Clubs
       ranks: 1 - 13 (1 = Ace, 11 = Jack, 12 = Queen, 13 = King)
       If an invalid rank is provided, sets the rank to 2
       Accepts lower or upper case characters for suit
    */
    Card(char ,int);


    /* Returns the Card's suit
    */
    char getSuit() const;
    
    /* Returns the Card's rank as an integer
    */
    int getRank() const;
    
    /* Outputs a Card in the following format: Rank of Suit
       For example, if the rank is 3 and the suit is h: 3 of Hearts
       Or, if the rank is 1 and the suit is d: Ace of Diamonds
       Or, if the rank is 12 and the suit is c: Queen of Clubs
       etc.
    */
    friend ostream & operator<<(ostream & , const Card& );
};

Card::Card() {
   this->suit = 'c';
   this->rank = 2;
}

Card::Card(char s, int r) {
   this->suit = s;
   this->rank = r;
   if (s == 'C') {
      this->suit = 'c';
   }
   else if (s == 'D') {
      this->suit = 'd';
   }
   else if (s == 'H') {
      this->suit = 'h';
   }
   else if (s == 'S') {
      this->suit = 's';
   }
   else {
      this->suit = suit;
   }
}

char Card::getSuit() const {
   return suit;
}

int Card::getRank() const {
   return rank;
}

ostream & operator<<(ostream & os, const Card& card) {
   string suits;

   if (card.getSuit() == 'c' || card.getSuit() == 'C') {
     suits = "Clubs";
   }
   else if (card.getSuit() == 'd' || card.getSuit() == 'D') {
      suits = "Diamonds";
   }
   else if (card.getSuit() == 'h' || card.getSuit() == 'H') {
      suits = "Hearts";
   }
   else if (card.getSuit() == 's' || card.getSuit() == 'S') {
      suits = "Spades";
   }

  if (card.getRank() == 1) {
   os << "Ace";
  }
  else if (card.getRank() == 11) {
   os << "Jack";
  }
  else if (card.getRank() == 12) {
   os << "Queen";
  }
  else if (card.getRank() == 13) {
   os << "King";
  }
  else {
   os << card.getRank();
  }

   os << " of " << suits;
   return os;

}


#endif