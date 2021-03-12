/*

  DoublyLinkedList.c

  Gehrig Wilcox <lougehrig10@gmail.com>

  3/9/21

*/


#include "DataStructures/LinkedList/DoublyLinkedList/DoublyLinkedList.h"
#include "DataStructures/LinkedList/SinglyLinkedList/SinglyLinkedList.h"
/*

  Places toAppend at the end of list

*/
void appendToDoublyLinkedList(doublyLinkedList_t* list, doublyLinkedList_t* toAppend){
  placeInDoublyLinkedList(list->prev,toAppend);
}
/*

  Places toPlace right after element

*/
void placeInDoublyLinkedList(doublyLinkedList_t* element, doublyLinkedList_t* toPlace){
  toPlace->prev=element;
  toPlace->next=element->next;
  toPlace->next->prev=toPlace;
  element->next=toPlace;
}
/*

  Removes toRemove from list

*/
void removeFromDoublyLinkedList(doublyLinkedList_t* list, doublyLinkedList* toRemove){
  toRemove->prev->next=toRemove->next;
  toRemove->next->prev=toRemove->prev;
}
