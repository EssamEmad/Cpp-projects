/*
 * File: pqueue.cpp (array version)
 * --------------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file implements the pqueue.h interface using a dynamic array as
 * the underlying representation.  Most of the code is already in place.
 * The only thing that is missing is the implementation of the actual
 * commands.
 * [TODO: extend the documentation]
 */

#include <iostream>
#include <string>
#include "error.h"
#include "pqueue.h"
using namespace std;

PriorityQueue::PriorityQueue() {
   // TODO: Fill in the necessary code
    array = new ValuePriorityPair[INITIAL_CAPACITY];
    count = 0;
    capacity = 10;
}

PriorityQueue::~PriorityQueue() {
   delete[] array;
}

int PriorityQueue::size() {
   return count;
}

bool PriorityQueue::isEmpty() {
   return (count == 0);
}

void PriorityQueue::clear() {
    delete[] array;
}

void PriorityQueue::enqueue(string value, double priority) {
    int pivot = 0;
    if(size() +1 > capacity)//<---------------------------------- check count
        expandCapacity();
    if(!isEmpty()){
        for(int i = 0; i < size(); i++){
            if(priority < array[i].priority){
                pivot = i;
                break;
            }
            pivot = i+1;
        }
    //shifting all values
        for(int i = size(); i > pivot; i--){
            array[i] = array[i-1];
        }
     }
    array[pivot].priority = priority;
    array[pivot].value = value;
    count ++;
}

string PriorityQueue::dequeue() {
    if(isEmpty()) return "Queue is empty";
    string returnString = array[0].value;
    for(int i = 1; i < size(); i++)
        array[i-1] = array[i];
    count--;
    return returnString;
}

string PriorityQueue::peek() {
    if(isEmpty()) return "Queue is empty";
    return array[0].value;
}

double PriorityQueue::peekPriority() {
    if(isEmpty()) return -1;
    return array[0].priority;
}

/*
 * Implementation notes: copy constructor and assignment operator
 * --------------------------------------------------------------
 * The constructor and assignment operators follow the standard
 * paradigm described in the textbook.
 */

PriorityQueue::PriorityQueue(const PriorityQueue & src) {
   deepCopy(src);
}

PriorityQueue & PriorityQueue::operator=(const PriorityQueue & src) {
   if (this != &src) {
      if (array != NULL) delete[] array;
      deepCopy(src);
   }
   return *this;
}
