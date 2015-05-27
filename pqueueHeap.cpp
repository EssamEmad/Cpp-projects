/*
 * File: pqueue.cpp (heap version)
 * -------------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file implements the pqueue.h interface using a heap as the
 * underlying representation.  Only the copy constructor and assignment
 * operator are included.  Your job is to include definitions for the
 * other exported methods and to make a change to the definition of the
 * assignment operator so that it deletes any old storage.
 * [TODO: extend the documentation]
 */

#include <iostream>
#include <string>
#include "error.h"
#include "pqueue.h"
using namespace std;

// TODO: Add your method definitions here

/*
 * Implementation notes: copy constructor and assignment operator
 * --------------------------------------------------------------
 * The constructor and assignment operators follow a standard paradigm,
 * as described in the textbook.
 */
PriorityQueue::PriorityQueue(){
}
PriorityQueue::~PriorityQueue(){
    delete[] pqueue;
}

PriorityQueue::PriorityQueue(const PriorityQueue & src) {
   deepCopy(src);
}

PriorityQueue & PriorityQueue::operator=(const PriorityQueue & src) {
   if (this != &src) {
      // TODO: Include code to delete any data from the old queue
      deepCopy(src);
   }
   return *this;
}
void PriorityQueue::enqueue(string value, double priority)
{
    node nodet;
    nodet.value = value;
    nodet.priority = priority;
    if(size()== capacity)
        expand();
    count++;
    pqueue[size()] = nodet;
    bubbleUp(size());

}


/* helper method returns the effective size of the array*/

int PriorityQueue::size()
{
    return count;
}




void PriorityQueue::bubbleUp( int location )
{
    if(size() == 1) return;
    node dummy;
    if(location /2 == 0){
        //swap with element number 1 with location
        dummy = pqueue[1];
        pqueue[1] = pqueue[location];
        pqueue[location] = dummy;
    } else if(pqueue[location].priority > pqueue[location/2].priority){
        //swap:
        dummy = pqueue[location/2];
        pqueue[location/2] = pqueue[location];
        pqueue[location] = dummy;
        bubbleUp(location/2);
    }

}

void PriorityQueue::expand()
{
    node * newArray = new node[capacity *2];
    for(int i = 1; i <= size();i++) {
        newArray[i] = pqueue[i];
    }
    delete[] pqueue;
    pqueue = newArray;
}

string PriorityQueue::dequeue()
{
    string value = pqueue[1].value;
    pqueue[1] = pqueue[size()];
    pqueue[size()] = pqueue[0];
    count--;
    heapify(1);
   cout<<"-----------------"<<endl;
    for(int i = 1; i <= size();i++){
        cout<<pqueue[i].value<<endl;
    }

return value;
}

void PriorityQueue::heapify(int location)
{
    //checks if there are children
    if(2*location + 1 > size()) return;
    //if parent is smaller than both or any of the children
    if(pqueue[location].priority < pqueue[2*location].priority
      ||pqueue[location].priority < pqueue[2*location + 1].priority){
        // next 3 lines puts the position of the greater child to x
        int x =
          pqueue[2*location].priority < pqueue[2*location + 1].priority
                ? 2*location + 1: 2*location;
       node dummy = pqueue[location];
       pqueue[location] = pqueue[x];
       pqueue[x] = dummy;
       heapify(x);
    }
}



