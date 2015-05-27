/*
 * File: WordLadder.cpp
 * --------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the word ladder problem
 * on Assignment #2.
 * [TODO: extend the documentation]
 */

#include <iostream>
#include "console.h"
#include "lexicon.h"
#include "queue.h"
#include "simpio.h"
#include "vector.h"
using namespace std;


void getInput(string & firstWord, string & lastWord);
void getInput(string & firstWord, string & lastWord);
Vector<string> assignLadders(string firstWord, string lastWord, Lexicon &english);
bool foundInQueue(Queue<Vector<string> >  q, string & word);
bool foundInVector(Vector<string> v, string word);


const int NUMBER_LETTERS = 26;
const string ALPHABATIC = "abcdefghijklmnopqrstuvwxyz";

int main() {
	// [TODO: fill in the code]
    string firstWord, lastWord;
    Lexicon english ("EnglishWords.txt");
    Vector<string> empty;
    getInput(firstWord, lastWord);
    Vector <string> after = assignLadders(firstWord, lastWord, english);
    if(after.equals(empty)) cout<<"no trail" << endl;
    else{
        for(int i = 0; i<after.size(); i++){
            cout<<after[i]<<"--->";
        }
    }
	return 0;
}



/* gets input from the user
 */
void getInput(string & firstWord, string & lastWord)
{
    cout<<"please enter the first word: ";
    firstWord = getLine();
    cout<<"please enter the last word: ";
    lastWord = getLine();
}

Vector<string> assignLadders(string firstWord, string lastWord, Lexicon &english)
{
    string manipulatefirstWord = firstWord;
    Queue< Vector<string> > q;
    Vector<string> chosen;
    Vector< string> vec;
    vec.add(firstWord);
    chosen.add(firstWord);
    q.enqueue(vec);

    while(!q.isEmpty()){
        Vector<string> v = q.dequeue();
        if(v[v.size()-1]== lastWord) return v;

        for(int i = 0; i < firstWord.size(); i++){
            manipulatefirstWord = v[v.size()-1];
            for(int j = 0; j < NUMBER_LETTERS; j++){
               manipulatefirstWord[i] = ALPHABATIC[j];
               if(english.contains(manipulatefirstWord)){
                   //if(!foundInQueue(q,manipulatefirstWord) && manipulatefirstWord != firstWord
                        //   && !foundInVector(v,manipulatefirstWord)){
                   if(!foundInVector(chosen,manipulatefirstWord)){
                       Vector<string> manipVec = v;
                       manipVec.add(manipulatefirstWord);
                       chosen.add(manipulatefirstWord);
                       q.add(manipVec);
                   }
               }
            }
            //manipulatefirstWord = firstWord;
        }


    }
    Vector<string> empty;
    return empty;

}

bool foundInQueue(Queue<Vector<string> >  q, string & word)
{
    while(!q.isEmpty()){
        Vector <string> v = q.dequeue();
        for(int i = 0; i<v.size(); i++){
            if(v[i] == word) return true;
        }
    }
    return false;
}

bool foundInVector(Vector<string> v, string word)
{
    for(int i = 0; i< v.size(); i++){
        if(v[i] == word)return true;
    }
    return false;
}


























