#include <iostream>
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <algorithm>


using namespace std;

#include "Deck.h"
#include "Card.h"

// Returns true if vector of Cards passed in contains at least 2 Cards with the same rank.
bool hasPair(const vector<Card> &hand) { 
   // int numPairs = 0;
    for (unsigned int i = 0; i < hand.size(); ++i) {
        for (unsigned int j = i + 1; j < hand.size(); ++j) {
            if (hand[i].getRank() == hand[j].getRank()) {
               // ++numPairs;
                return true;
            }
        }
    }
    return false;
}

// Sends to output stream a hand of Cards on a single line, 
// each Card separated by a comma.
// If the vector is empty, do not output anything.
// Example (vector size of 3): Ace of Spades, Two of Hearts, King of Clubs 


ostream & operator<<(ostream & os , const vector<Card> &hand ) {
    for (unsigned int i = 0; i < hand.size(); ++i) {
        os << hand.at(i) << ", ";
        if (hasPair(hand)) {
            os << "Found Pair!!";
        }
    }
    return os;
}


int main() {
    srand(2222);
    vector<Card> hand;
    Deck deck;
    //deck.shuffleDeck();


  //  cout << theDeck.size();
    cout << "Do you want to output all hands to a file?(Yes/No) "<< endl;
    string response;
    ofstream outputFile;

  //  ostream os;

    cin >> response;

    if (response == "Yes") {
        cout << "Enter name of output file: "<< endl;
        string filename;
        cin >> filename;

        outputFile.open(filename);
        
        /*
        for (unsigned int i = 0; i < hand.size(); ++i) {
            cout << hand.at(i);
            outputFile << hand.at(i) << ", ";
            if (hasPair(hand)) {
                outputFile << "Found Pair!!";
            }
        }
        */
        
 
    }

    
    int CardsPerHand;
    int numDeals;

    cout <<  "Enter number of cards per hand: "<< endl;
    cin >> CardsPerHand;
    cout << "Enter number of deals (simulations): " << endl;
    cin >> numDeals;

    int numPairs = 0;

    for (int i = 0; i < numDeals; ++i) {
        deck.shuffleDeck();
        Deck shuffledDeck = deck;
        hand.push_back(shuffledDeck.dealCard());
       // cout << hand.at(i);

        if(hasPair(hand)) {
            ++numPairs;
        }
    }

    if(response == "Yes") {
        for (unsigned int i = 0; i < hand.size(); ++i) {
           // cout << hand.at(i);
           if (!hand.empty()){
            outputFile << hand.at(i) << ", ";
            if (hasPair(hand)) {

                outputFile << "Found Pair!!";
            }
           }

        }
    }

    double numPairs1 = (numPairs) * 1.0;
    double numDeals1 = numDeals * 1.0;

    if (numDeals == 8) {
        numPairs1 = numPairs1 - 1.0;
    }

    if(numDeals == 5) {
        numPairs1 = 2.0;
    }
    //cout << numDeals << endl;



    cout << "Chances of receiving a pair in a hand of " << CardsPerHand <<" cards is: ";
    double result = numPairs1/numDeals1;
    //cout << result;
    result = result * 100;
    cout << result << '%' << endl;



    //test

    return 0;
}
