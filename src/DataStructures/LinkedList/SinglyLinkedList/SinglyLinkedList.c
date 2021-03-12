/*

  SinglyLinkedList.c

  Gehrig Wilcox <lougehrig10@gmail.com>

  3/9/21

*/

#include "DataStructures/LinkedList/SinglyLinkedList/SinglyLinkedList.h"

/*

  Places toAppend at the end of list

  Loops through until it finds a null pointer. Replaces null pointer with toAppend

*/
void appendToSinglyLinkedList(singlyLinkedList_t* list, singlyLinkedList_t* toAppend){
  while(!list->next==NULL)list=list->next;
  list->next=toAppend;
}
/*

  Places toPlace right after element

*/
void placeInSinglyLinkedList(singlyLinkedList_t* element, singlyLinkedList_t* toPlace){
  toPlace->next=element->next;
  element->next=toPlace;
}
/*

  Removes toRemove from list

*/
void removeFromSinglyLinkedList(singlyLinkedList_t* list, singlyLinkedList* toRemove){
  while(!list->next==toRemove)list=list->next;
  list->next=toRemove->next;
}
