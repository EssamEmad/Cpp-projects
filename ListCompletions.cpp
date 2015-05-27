/*
 * File: ListCompletions.cpp
 * -------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the cell phone mind-reading problem
 * from Assignment #3
 * [TODO: extend the documentation]
 */

#include <iostream>
#include "console.h"
#include "simpio.h"
#include "lexicon.h"
#include "set.h"
using namespace std;

/* Function prototypes */

void listCompletions(string digits, Lexicon & lex);
void listCompletions(string digits, Lexicon & lexicon);
Vector<string> wrapper(Lexicon & lexicon, Vector<string> digitsAsVector, string word, Vector<string> & returnVector);
Vector<string> mapingUp (string digits);
Set<string> checkValidity(string word, Lexicon &lexicon, string alphabat, Set<string> &list);
void print(string word);

/* Main program */

int main() {
   Lexicon english("EnglishWords.dat");
   cout << "Cell phone mind-reading problem" << endl;
   while (true) {
      cout << "Enter a set of digits: ";
      string digits = getLine();
      if (digits == "" || digits == "quit") break;
      cout << "The words beginning with those digits are:" << endl;
      listCompletions(digits, english);
   }
   return 0;
}

/*
 * Function: listCompletions
 * Usage: listCompletions(digits, lexicon);
 * ----------------------------------------
 * Lists all the words in the lexicon that begin with the letters
 * corresponding to the specified digits on a telephone keypad.
 */

void listCompletions(string digits, Lexicon & lexicon) {
   // [TODO: Complete the code]
    Vector<string> digitsAsVector = mapingUp(digits);
    Vector<string> emptyVec;
    Vector<string> possibleWordsList = wrapper(lexicon , digitsAsVector, "",emptyVec );
    //for(int i = 0; i < possibleWordsList.size(); i++) cout<<possibleWordsList[i]<<endl;
    //checkValidity(possibleWordsList, lexicon,alphabat);
    string alphabat = "abcdefghijklmnopqrstuvwxyz";
    Set<string> empty;
    while(! possibleWordsList.isEmpty()){
        string word = possibleWordsList[0];
        possibleWordsList.remove(0);
        Set<string> list = checkValidity(word,lexicon, alphabat,empty);
    }
}
/* creates a new map and creates
 * a new vector of the digits string
 */
Vector<string> mapingUp (string digits)
{
    Map<char, string> m;
    m.add('2',"abc");
    m.add('3',"def");
    m.add('4',"ghi");
    m.add('5',"jkl");
    m.add('6',"mno");
    m.add('7',"pqrs");
    m.add('8',"tuv");
    m.add('9',"wxyz");
    Vector<string> digitVector;
    for(int i = 0; i<digits.size(); i++){
        digitVector.add(m[digits[i]]);
    }
    return digitVector;
}

Vector<string> wrapper( Lexicon & lexicon, Vector<string>  digitsAsVector, string word, Vector<string> & returnVector)
{
    string letters;
   if( ! digitsAsVector.isEmpty()){
    letters = digitsAsVector[0];
   digitsAsVector.remove(0);

   }else{
       if(lexicon.containsPrefix(word))
            returnVector.add(word);
       return returnVector;
   }
   for(int i = 0; i< letters.size(); i++){
       word += letters[i];
       wrapper(lexicon, digitsAsVector, word,returnVector);
       word.erase(word.size()-1,word.size());
   }
   return returnVector;
}


Set<string> checkValidity(string word, Lexicon &lexicon, string alphabat, Set<string> &list)
{
      for(int i = 0; i<alphabat.size(); i++){
        if(lexicon.containsPrefix(word)){
            if(lexicon.contains(word)){
                if(! list.contains(word)){
                    list.add(word);
                    cout<<word<<endl;
                 }
              }

                //if(alphabat.empty()) return;
                word += alphabat[i];
                //alphabat.erase(0,1);
                checkValidity(word, lexicon, alphabat, list);
                if(!lexicon.containsPrefix(word)) word.erase(word.size()-1);
        } else break;
      }
      return list;

}







