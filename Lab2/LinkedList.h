#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

struct Node {
   int data;
   Node * next;
};

// Functions already written.

Node * createNode (int n);
Node * insertAtHead (Node * top, int n);
Node * insertAtTail (Node * top, int n);
Node * getLast (Node * top);
void printList (Node * top);

// Functions to write.

int size (Node * top);
bool contains (Node * top, int key);
bool isEqual (Node * top1, Node * top2);
Node * insertSorted (Node * top, int n);

Node * printList2 (Node * top);

#endif
