#include <iostream>
#include <cstdlib>
#include "LinkedList.h"

using namespace std;


Node * createNode (int n) {
   Node * newNode; 
   
   newNode = new Node;
   newNode->data = n;
   newNode->next = NULL;
   return newNode;
}



Node * insertAtHead (Node * top, int n) {
   Node * newNode;
   
   newNode = createNode (n);
   newNode->next = top; 			// this works even if the list is empty (i.e., top = NULL)
   top = newNode;
   
   return top;          			// return pointer to new head of list
}   



Node * insertAtTail (Node * top, int n) {
   Node * newNode;
   Node * lastNode;
   
   newNode = createNode (n);
   lastNode = getLast (top);
   
   if (lastNode == NULL)   			// linked list has no elements
      top = newNode;       			// let top be the address of the node just created
   else                    			// let lastNode refer to the node just created
      lastNode->next = newNode;
   
   return top;             			// return top in case it got changed
}



Node * getLast (Node * top) {
  
   Node * curr;
   Node * last;
   
   last = NULL;     
   curr = top;
   while (curr != NULL) {
      last = curr;
      curr = curr->next;
   }
   
   return last;
}



void printList (Node * top) {

   while (top != NULL) {
      cout << top->data << "\t";
      top = top->next;
   }

   cout << "\n";
}



int size(Node * top) {
    int size = 0;
    while (top != NULL) {
        top = top->next;
        size++;
    }
    return size;
}

bool contains(Node * top, int key) {
    while (top != NULL) {
        if (top->data == key) {
            return true;
        }
        top = top->next;
    }
    return false;
}

bool isEqual(Node * top1, Node * top2) {
    while (top1 != NULL && top2 != NULL) {
        if (top1->data != top2->data) {
            return false;
        }
        top1 = top1->next;
        top2 = top2->next;
    }
    return top1 == NULL && top2 == NULL;
}

Node * insertSorted(Node * top, int n) {
    Node * newNode = createNode(n);
    if (top == NULL || top->data >= n) {
        newNode->next = top;
        top = newNode;
    } else {
        Node * curr = top;
        while (curr->next != NULL && curr->next->data < n) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
    return top;
}


Node * printList2 (Node * top) {

   while (top != NULL) {
      cout << top->data << "\t";
      top = top->next;
   }

   cout << "\n";

	return top;
}
