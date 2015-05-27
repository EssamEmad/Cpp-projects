/*
 * File: Boggle.cpp
 * ----------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the main starter file for Assignment #4, Boggle.
 * [TODO: extend the documentation]
 */
 
#include <iostream>
#include "gboggle.h"
#include "grid.h"
#include "gwindow.h"
#include "lexicon.h"
#include "random.h"
#include "simpio.h"
using namespace std;

/* Constants */

const int BOGGLE_WINDOW_WIDTH = 650;
const int BOGGLE_WINDOW_HEIGHT = 350;

const string STANDARD_CUBES[16]  = {
   "AAEEGN", "ABBJOO", "ACHOPS", "AFFKPS",
   "AOOTTW", "CIMOTU", "DEILRX", "DELRVY",
   "DISTTY", "EEGHNW", "EEINSU", "EHRTVW",
   "EIOSST", "ELRTTY", "HIMNQU", "HLNNRZ"
};
 
const string BIG_BOGGLE_CUBES[25]  = {
   "AAAFRS", "AAEEEE", "AAFIRS", "ADENNN", "AEEEEM",
   "AEEGMU", "AEGMNN", "AFIRSY", "BJKQXZ", "CCNSTW",
   "CEIILT", "CEILPT", "CEIPST", "DDLNOR", "DDHNOT",
   "DHHLOR", "DHLNOR", "EIIITT", "EMOTTT", "ENSSSU",
   "FIPRSY", "GORRVW", "HIPRRY", "NOOTUW", "OOOTTU"
};
struct coord  {int x; int y;};

/* Function prototypes */

void welcome();
void giveInstructions();
void setBoard(int charIndex, Grid<char> &board);
void shakeShakeShake(Vector<string> &vec);
bool wordCanBeFormedWrapper(string word, Grid<char> &board);
void takeInput(Grid<char> &board);
void computerWrapper(Grid<char> &board);

/* Main program */

int main() {
   GWindow gw(BOGGLE_WINDOW_WIDTH, BOGGLE_WINDOW_HEIGHT);
   coord c;
   c.x = 0;
   c.y = 0;
   initGBoggle(gw);
   welcome();
   giveInstructions();
   drawBoard(4,4);
   int stringIndex = randomInteger(0,6);
   Grid<char> board(4,4);
   setBoard(stringIndex,board);
   takeInput(board);
   computerWrapper(board);
   return 0;
}

/*
 * Function: welcome
 * Usage: welcome();
 * -----------------
 * Print out a cheery welcome message.
 */

void welcome() {
   cout << "Welcome!  You're about to play an intense game ";
   cout << "of mind-numbing Boggle.  The good news is that ";
   cout << "you might improve your vocabulary a bit.  The ";
   cout << "bad news is that you're probably going to lose ";
   cout << "miserably to this little dictionary-toting hunk ";
   cout << "of silicon.  If only YOU had a gig of RAM..." << endl << endl;
}

/*
 * Function: giveInstructions
 * Usage: giveInstructions();
 * --------------------------
 * Print out the instructions for the user.
 */

void giveInstructions() {
   cout << endl;
   cout << "The boggle board is a grid onto which I ";
   cout << "I will randomly distribute cubes. These ";
   cout << "6-sided cubes have letters rather than ";
   cout << "numbers on the faces, creating a grid of ";
   cout << "letters on which you try to form words. ";
   cout << "You go first, entering all the words you can ";
   cout << "find that are formed by tracing adjoining ";
   cout << "letters. Two letters adjoin if they are next ";
   cout << "to each other horizontally, vertically, or ";
   cout << "diagonally. A letter can only be used once ";
   cout << "in each word. Words must be at least four ";
   cout << "letters long and can be counted only once. ";
   cout << "You score points based on word length: a ";
   cout << "4-letter word is worth 1 point, 5-letters ";
   cout << "earn 2 points, and so on. After your puny ";
   cout << "brain is exhausted, I, the supercomputer, ";
   cout << "will find all the remaining words and double ";
   cout << "or triple your paltry score." << endl << endl;
   cout << "Hit return when you're ready...";
   getLine();
}

// [TODO: Fill in the rest of the code]


/*assigns the characters to the string
 */
void setBoard(int charIndex, Grid<char> &board)
{
    Vector<string> words;
    for(int counter = 0; counter < 16; counter++) words.add(STANDARD_CUBES[counter]);
    shakeShakeShake(words);
   int arrayStringIndexer = 0;
   for(int i = 0; i<4;i++){
       for ( int j = 0; j < 4; j++){
           string dummy = words[arrayStringIndexer++];
           board[i][j] = dummy[charIndex];
           labelCube(i,j,dummy[charIndex]);
       }
   }
}

//shakes the vector such that the characters are in random positions

void shakeShakeShake(Vector<string> &vec)
{
    string dummyForSwap;
    for( int i = 0; i < vec.size(); i++){
        int randomIndex = randomInteger(i,vec.size()-1);
        dummyForSwap = vec[i];
        vec[i] = vec[randomIndex];
        vec[randomIndex] = dummyForSwap;
    }
}

/* Function: takeInput();
 * usage: takeInput(Grid<char>board);
 * Description: takes input from the user and makes four checks:
 * 1- the word is more than four characters
 * 2- the word is in the English dictionary
 * 3- the word wasn't previously chosen
 * 4- the word can be formed in the lexicon
 * P.S passing board by reference only for effeiciency
 */

void takeInput(Grid<char> &board)
{
    cout<<"Please enter the words you find and hit enter if you are done"<<endl;
    Set<string> wordsChosen;
    Lexicon lex;
    while(true){
        string input = getLine();
        if(input == "")break;
        //if(input.size() >= 4 && lex.contains(input) && !wordsChosen.contains(input) ){
            if(wordCanBeFormedWrapper(input,board)) cout<<input<<endl;


         else cout<<"Nice try punk!"<<endl;
    }
}

/*wordCaneBeFormed(int row, int column, string word)
 * checks if the word can be formed in the baord
 */

bool wordCanBeFormed(int row, int column, string word, Grid<char> & board)
{
   if(word.empty()) return true;
   char check = word[0];
   for(int i = 0; i < 4; i++){
       for(int j = 0; j < 4; j++){
           if(check == board.get(i,j)){
               if((i-row)/2 == 0 && (j-column)/2 ==0 && (i != row  || j != column)){
                word.erase(0,1);
                if(wordCanBeFormed(i,j,word, board )) return true;
               }

           }
       }
   }
   return false;

}
/*
 * word can be formed wrapper also gets the co-ordinates of the first letter to pass it to
 * the original recursive function
 */
bool wordCanBeFormedWrapper(string word, Grid<char> &board)
{
    char x;
    int row, column;
    for( row = 0; row < 4; row++){
        for ( column = 0; column < 4; column ++){
            x =  board.get(row,column);
            if(x == word[0]){
                word.erase(0,1);
                if(wordCanBeFormed(row,column,word,board)) return true;
                word = x + word.substr(0);

             }
        }
    }


    return false;
}
/* computer's recursive function
 * searches the board for all the words that could be formed
 * and neglecting dead end searches
 * Checks:
 * 1) The word is greater than four characters
 * 2) The word is in the english dictionary
 * 3) The word can be formed
 * 4) The word was not already found
 */
bool computer(string wordFormed, Grid<char> &board, Set<string> &wordsFormed, Lexicon &lex, int row, int column)
{
    for(int i = 0; i<4; i++){
        for(int j = 0; j < 4; j++){
            if((i-row)/2 == 0 && (j-column)/2 ==0 && (i != row || j != column)){
                wordFormed += board.get(i,j);
                if(lex.containsPrefix(wordFormed)){
                    if(wordFormed.size() >= 4 && lex.contains(wordFormed) && !wordsFormed.contains(wordFormed)){
                        // word is found
                        cout<<wordFormed<<endl;
                        wordsFormed.add(wordFormed);
                    } else {
                        if(computer(wordFormed, board, wordsFormed, lex, i, j)){
                            //word is found
                            cout<<wordFormed<<endl;
                            wordsFormed.add(wordFormed);
                        } else wordFormed.erase(wordFormed.size()-1);
                    }
                }
             }
            }
        }
    return false;
    }


/*Computer's wrapper
 */

void computerWrapper(Grid<char> &board)
{
    Lexicon lex;
    Set<string> s;
    computer("",board, s, lex, -1,0);
}



