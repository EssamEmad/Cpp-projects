/*
 * File: RandomWriter.cpp
 * ----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the random writer problem
 * on Assignment #2.
 * [TODO: extend the documentation]
 */

/*#include <fstream>
#include <iostream>
#include <string>
#include "console.h"
#include "map.h"
#include "random.h"
#include "strlib.h"
#include "vector.h"
using namespace std;

int main() {
	// [TODO: fill in the code]
	return 0;
}*/
#include "map.h"
#include <iostream>
#include"simpio.h"
#include "vector.h"
#include "string.h"
#include "console.h"
#include <fstream>
using namespace std;
void print(string key, Vector<string> value)
{
    //cout<<"key = "<<key<<endl;
}

void openFile(ifstream & in);
int getOrder(string prompt);
void getHighestOccurence (string key, Vector<string> value);
string getHighestOccurenceSeed(Vector<string> &value);
void print2000 (Map< string, Vector<string> > & map, string seed, string afterCharacter, int markovOrder);





/* constants */
const string OUTPUT_FILE_NAME = "TomSawyer.txt";  //<<<<<<<<<<<<<<<<<<<<<<------------------------------------ write output file name
string keyInMapping;
int main()
{
    /* sorts data into map till line 226
     * */
    Map<string, Vector<string> > map;
    ifstream in;
    openFile(in);
    int markovOrder = getOrder("Please enter the markov order to use: ");
    string character;
    string afterAsString;
    for(int i = 0; i<markovOrder; i++){
        character += in.get();
        //cout << "character = "<<character<< endl;
        if(in.fail()) break;
    }
    char after = in.get();
    afterAsString += after;
    map[character].add(afterAsString);
    while(true){
        character.erase(0,1);
        //cout << "character = "<<character<< endl;
        character += after;
        //cout << "character = "<<character<< endl;
        if(in.fail()) break;
        afterAsString = "";
        after = in.get();
        afterAsString += after;
        map[character].add(afterAsString);
    }
   map.mapAll(print);
   /* gets the highest occurence key
    */
    map.mapAll(getHighestOccurence);
   string key = keyInMapping;

   /*prints to the output
    */
   string afterCharacter = getHighestOccurenceSeed(map[key]);
   print2000(map, key, afterCharacter, markovOrder);


    return 0;

}
void openFile(ifstream & in)
{

    while(true){
        cout << "Please enter the file name: ";
        string fileName =getLine();
        in.open(fileName);
        if(!in.fail()) break;
        else{
            cout<<" nice try punk"<<endl;
            in.clear();
        }
    }
}

int getOrder(string prompt)
{
    cout<< prompt;
    return getInteger();
}

void getHighestOccurence (string key, Vector<string> value)
{
    int numOccurences = 0;
    if(value.size() >= numOccurences){
        numOccurences = value.size();
        keyInMapping = key;
    }
}

string getHighestOccurenceSeed(Vector<string> & value)
{
    int dummy = 0;
    int counter = 0;
    string returnString;
    for(int i = 0; i < value.size(); i++) {
        for(int j= i + 1; j<value.size(); j++){
            if(value[i] == value[j]) counter ++;
        }
        if(counter >= dummy){
            dummy = counter;
            returnString = value[i];
        }

    }
    return returnString;
}



void print2000 (Map< string, Vector<string> > & map, string seed, string afterCharacter, int markovOrder)
{
    string output;
    ofstream out;
    out.open(OUTPUT_FILE_NAME);
   // for(int i = 0; i< markovOrder; i++){
        output.append(seed);
    //}

    Vector<string> value;
    for( int i = 0; i<2000 - markovOrder; i++){ // 2 characters are already printed (initial seeds
        output.append(afterCharacter);
        seed.erase(0,1);
        seed.append(afterCharacter);
        value = map.get(seed);
        afterCharacter.erase(0,1);
        afterCharacter.append(getHighestOccurenceSeed(value));
        cout<<output<<endl;
    }
    cout << output<<endl;
}


















