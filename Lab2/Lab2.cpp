#include <iostream>
#include "LinkedList.h"

using namespace std;

//adding this in - not part of lab just good practice
void deleteList(Node* curr) {
    if (curr == nullptr) {
        return;
    }
    deleteList(curr->next);
    delete curr;
}


int main() {
    //init to NULL or nullptr
    Node * top = nullptr;
    Node * secondList = nullptr;
    Node * thirdList = nullptr;
    
    cout << "COMP 2611 - Lab 2" << endl;
    cout << "=================" << endl;
    cout << endl;

    // Question 1
   
    // Insert 17, 23, and 250 at the head of a list and print the list
    top = insertAtHead(top, 17);
    top = insertAtHead(top, 23);
    top = insertAtHead(top, 250);
    cout<<"List after first round of inserts:\t";
    printList(top);
   
    // Insert 4, 10, 500, 25 at the tail of the list and print the list
    top = insertAtTail(top, 4);
    top = insertAtTail(top, 10);
    top = insertAtTail(top, 500);
    top = insertAtTail(top, 25);
    cout<<"List after second round of inserts:\t";
    printList(top);
  
    // Question 2
    cout << "Full Linked List is:\t";
    printList(top);
    
    int num = 0;
    cout<<"Please enter a number to check if in list: ";
    cin >> num;
    string result = contains(top, num) ?  "Number is in list!" :  "Number is not in list!";
    cout << result << endl;

    // Create second list
    secondList = insertAtHead(secondList, 17);
    secondList = insertAtHead(secondList, 23);
    secondList = insertAtHead(secondList, 250);
    secondList = insertAtTail(secondList, 4);
    secondList = insertAtTail(secondList, 10);
    secondList = insertAtTail(secondList, 500);
    secondList = insertAtTail(secondList, 25);

    isEqual(top,secondList) ? cout << "Lists are equal (First and second list)" <<endl : cout << "Lists are not equal (First and second list) " <<endl;

    //Create third list
    thirdList = insertSorted(thirdList,250);
    thirdList = insertSorted(thirdList,23);
    thirdList = insertSorted(thirdList,17);
    thirdList = insertSorted(thirdList,4);
    thirdList = insertSorted(thirdList,10);
    thirdList = insertSorted(thirdList,500);
    thirdList = insertSorted(thirdList,25);
    cout<<"Third list:\t"<<endl;
    printList(thirdList);
    
    isEqual(top,thirdList) ? cout << "Lists are equal (First and third list)" <<endl : cout << "Lists are not equal (First and third list) " <<endl;
    // Question 3: Call printList2 twice
    cout<<"Printing list 1:\t"<<endl;
    top = printList2 (top);
    top = printList2 (top);
   
    cout << "\n*** End of Linked List Operations ***" << endl;
    //Delete lists when done
    deleteList(top);
    deleteList(secondList);
    deleteList(thirdList);
    return 0;
}

