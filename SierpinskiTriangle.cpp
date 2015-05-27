/*
 * File: SierpinskiTriangle.cpp
 * ----------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter code for the Sierpinski Triangle problem from
 * Assignment #3.
 * [TODO: extend the documentation]
 */

#include <iostream>
#include "gwindow.h"
#include "simpio.h"
#include "gmath.h"
#include "Lexicon.h"
using namespace std;

/* Main program */
void drawTriangle(int length, GWindow gw, double startX, double startY);
void drawFractals(int fractalsOrder, int length, GWindow gw, double x, double y);
bool findAnagram(string letters, Lexicon & english,
Vector<string> & words,string word);

int main() {
/*GWindow gw(2000, 900);
   // [TODO: Fill in the necessary code here]
   int length = getInteger("please enter the lenght: ");
   int nFractales = getInteger("Please enter the number of fractels");
   double x = (gw.getWidth() - length)/2;
   double y = (gw.getHeight() + (length* sinDegrees(60)))/2;
   drawTriangle(length, gw, x,y);
   drawFractals(nFractales,length, gw, x,y);*/
    cout<<"?"<<endl;
    string x = getLine();
    Lexicon lex;
    Vector<string> words;
    findAnagram(x,lex,words,"");
    cout<<words[0]<<endl;
   return 0;
}


void drawTriangle(int length, GWindow gw, double startX, double startY)
{
    struct point {int x ;int y;};
    point p;
    p.x = startX;
    p.y = startY;
    gw.drawPolarLine(p.x, p.y,length,60 );
    gw.drawLine(p.x,p.y,p.x + length, p.y);
    gw.drawPolarLine(p.x + length, p.y, length, 120);


}


void drawFractals(int fractalsOrder, int length,GWindow gw, double x, double y)
{
    fractalsOrder --;
    if(fractalsOrder<= 0) return;
    for( int i = 0; i <3; i++){
        switch(i){
        case 0 :
            drawTriangle(length/2, gw , x , y );
            drawFractals(fractalsOrder, length/2, gw,x,y );
            break;
        case 1 :
            drawTriangle(length/2, gw , x + ((length/2) * cosDegrees(60)), y - (sinDegrees(60)*(length/2)));
            drawFractals(fractalsOrder, length/2, gw,x + (length/2) * cosDegrees(60),y - (sinDegrees(60)*(length/2)) );
            break;
        case 2 :
            drawTriangle(length/2, gw , x + (length/2),y);
              drawFractals(fractalsOrder, length/2, gw, x + (length/2),y);

              break;
        }

    }
}


bool findAnagram(string letters, Lexicon & english,
Vector<string> & words,string word)
{
    int size = letters.size();
    for(int i = 0; i < size; i++){
      word += letters[i];
        letters.erase(i,i+2);
      if(english.contains(word)){
          words.add(word);
          if(findAnagram(letters,english,words,""))
              return true;
      } else if(english.containsPrefix(word)){
          if(ftgram(letters,english,words,word))
              return true;
          letters = letters.substr(0,i) + word[word.size()]
                  + letters.substr(i,letters.size());

          words.remove(words.size());
      }

    }
    return false;
}






















