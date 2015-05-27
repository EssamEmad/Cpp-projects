/*
 * File: CountFifteens.cpp
 * -----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter code for the CountFifteens problem from
 * Assignment #3.
 * [TODO: extend the documentation]
 */

#include <exception>
#include <iostream>
#include <string>
#include "card.h"
#include "console.h"
#include "error.h"
#include "simpio.h"
#include "tokenscanner.h"
#include "vector.h"
#include "Lexicon.h"
using namespace std;


/* Function prototypes */

int countFifteens(Vector<Card> & cards);

int count(Vector<Card> card , int sum);
void palindromes(string word);

/*
 * Main program
 * ------------
 * This test program does no error-checking on the input.  One of the
 * extensions you might consider is adding code to this program (and
 * possibly to the Card class) to allow the program to report errors.
 */

int main() {
   /*while (true) {
      string line = getLine("Enter a hand of cards: ");
      if (line == "") break;
      TokenScanner scanner(line);
      scanner.ignoreWhitespace();
      Vector<Card> hand;
      while (scanner.hasMoreTokens()) {
         hand.add(Card(scanner.nextToken()));
      }
      int nWays = countFifteens(hand);
      string plural = (nWays == 1) ? "" : "s";
      cout << nWays << " way" << plural << endl;
   }*/
    Lexicon lex;
    lex.mapAll(palindromes);
    for(string word : lex){
        palindromes(word);
    }
    cout<<""<<endl;


   return 0;
}

/*
 * Counts the number of ways of making a total of 15 from the vector of
 * cards.
 */

int countFifteens(Vector<Card> & cards) {
   // [TODO: Fill this in]
    return count(cards, 0);



}

int count(Vector <Card>  card ,int sum)
{
    int fifteens = 0;
   // if(sum >15) return fifteens;
   // for(int i = 0; i< card.size(); i++){
    while(!card.isEmpty()){
        int x = sum;
        sum += card[0].getRank();

        card.remove(0);
        if(sum == 15) return ++fifteens;

        fifteens += count(card, sum);
        sum = x;
    }
    return fifteens;
}

void palindromes(string word)
{
    for(int i = 0; i < word.size(); i++){
        if(i == word.size()-i)
            break;
        if(word[i] != word[word.size()-i])
            return;
    }
    cout<<word<<endl;
    }













