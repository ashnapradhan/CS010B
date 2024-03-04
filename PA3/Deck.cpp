#ifndef __DECK_H__
#define __DECK_H__

#include <vector>
#include <algorithm>
using namespace std;

#include "Card.h"

class Deck {
 private:
    vector<Card> theDeck;
    vector<Card> dealtCards;
 public:
    /* Constructs a Deck of 52 cards:
       Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King of each suit.
       Cards should start off in this order with the order of suits being:
       Clubs, Diamonds, Hearts, Spades. So, the Card at the top of the
       Deck should be the Ace of Clubs.
       
       For best efficiency, the top of Deck should be stored at 
       back end of vector.
    */
    Deck();

    /* Deals (returns) the top card of the deck. 
       Removes this card from theDeck and places it in dealtCards.
       As mentioned in comments for the constructor, 
       for best efficiency, the top card should come from the 
       back end of vector.
    */
    Card dealCard();


    /* Places all cards back into theDeck and shuffles them into random order.
       Use random_shuffle function from algorithm library.
       To pass test harness, this function must go forward through dealtCards
       pushing each Card onto the back end of theDeck, then clear dealtCards.
       Do not use pop_back on dealtCards.
    */
    void shuffleDeck();


    /* returns the size of the Deck (how many cards have not yet been dealt).
    */
    unsigned deckSize() const;
};

//test
Deck::Deck() {
  int temp1 = 13;
  int temp2 = 13;
  int temp3 = 13;
  int temp4 = 13;

  for (unsigned int i = 0; i < 13; ++i) {
      theDeck.push_back(Card('s' , temp1));
      --temp1;
   }
   for (unsigned int i = 13; i < 26; ++i) {
      theDeck.push_back(Card('h' , temp2));
      --temp2;
   }
   for (unsigned int i = 26; i < 39; ++i) {
      theDeck.push_back(Card('d' , temp3));
      --temp3;
   }
   for (unsigned int i = 39; i < 52; ++i) {
      theDeck.push_back(Card('c' , temp4));
      --temp4;
   }

}

Card Deck::dealCard() {
   Card temp = theDeck.at(deckSize()-1);
   theDeck.pop_back();
   dealtCards.push_back(temp);
   return temp;
}


void Deck::shuffleDeck() {
   while (!dealtCards.empty()) {
      theDeck.push_back(dealtCards.back());
      dealtCards.pop_back();
   }
   dealtCards.clear();
   random_shuffle(theDeck.begin(), theDeck.end());
   //cout << "will shuffle";
}

unsigned Deck::deckSize() const{
   return theDeck.size();
}

#endif

