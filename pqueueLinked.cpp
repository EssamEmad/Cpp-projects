/*
 * File: pqueue.cpp (linked-list version)
 * --------------------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file implements the pqueue.h interface using a linked list as the
 * underlying representation.  Only the copy constructor and assignment
 * operator are included.  Your job is to include definitions for the
 * other exported methods.
 * [TODO: extend the documentation]
 */

#include <iostream>
#include <string>
#include "error.h"
#include "pqueue.h"
using namespace std;


// TODO: Add your method definitions here
PriorityQueue::PriorityQueue()
{
    first = new cell;
    first->next = NULL;
    count = 0;
}
PriorityQueue::~PriorityQueue()
{
}


int PriorityQueue::size() {
   return count;
}

bool PriorityQueue::isEmpty() {
   return (count == 0);
}

void PriorityQueue::clear() {
    //delete[] array;
}
// Cats and dogs are sleeping together here <----------------------------------
void PriorityQueue::enqueue(string value, double priority)
{
    cell *cursor1, *cursor2, *newCell;
    cursor1 = cursor2 = first;
    newCell = new cell;
    newCell->value = value;
    newCell->priority = priority;
    newCell->next = NULL;
    if(size() == 0){
       delete first;
        first = newCell;
        count++;
        return;
    }
    for(int i = 0; i < size(); i++){
        if(cursor1->priority > priority)
            break;
        cursor2 = cursor1;
        cursor1 = cursor1->next;
    }
    //first one
    if(cursor1 == cursor2){
        newCell->next = first;
        first = newCell;
        count++;
        return;
    }
    //last one
    if(cursor1 == NULL){
        cursor2->next = newCell;
        count++;
        return;
    }
    newCell->next = cursor2->next;
    cursor2->next = newCell;
    count++;

}

string PriorityQueue::dequeue() {
    cell *null;
    if(isEmpty()) return "Queue is empty";
    string returnString = first->value;
    null = first->next;
    delete first;
    first = null;
    count--;
    return returnString;
}

string PriorityQueue::peek() {
    if(isEmpty()) return "Queue is empty";
    return first->value;
}

double PriorityQueue::peekPriority() {
    if(isEmpty()) return -1;
    return first->priority;
}
/* finds the pivot
 */
/*cell *PriorityQueue::findPivot(double priority, cell *dummy)
{
    if(priority < dummy->priority)
        return dummy;
    if(dummy->next == NULL) return dummy;
    dummy = dummy->next;
    return findPivot(priority, dummy);
}
*/

/*
 * Implementation notes: copy constructor and assignment operator
 * --------------------------------------------------------------
 * The constructor and assignment operators follow a standard paradigm,
 * as described in the textbook.
 */

PriorityQueue::PriorityQueue(const PriorityQueue & src) {
   deepCopy(src);
}

PriorityQueue & PriorityQueue::operator=(const PriorityQueue & src) {
   if (this != &src) {
      clear();
      deepCopy(src);
   }
   return *this;
}
