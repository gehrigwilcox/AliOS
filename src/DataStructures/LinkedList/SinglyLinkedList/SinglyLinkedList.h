/*

  SinglyLinkedList.h

  Gehrig Wilcox <lougehrig10@gmail.com>

  3/9/21

*/

#ifndef __SINGLY_LINKED_LIST_H__
#define __SINGLY_LINKED_LIST_H__

typedef struct {
  void* next;
} singlyLinkedList_t;

/*

  Places toAppend at the end of list

*/
void appendToSinglyLinkedList(singlyLinkedList_t* list, singlyLinkedList_t* toAppend);
/*

  Places toPlace right after element

*/
void placeInSinglyLinkedList(singlyLinkedList_t* element, singlyLinkedList_t* toPlace);
/*

  Removes toRemove from list

*/
void removeFromSinglyLinkedList(singlyLinkedList_t* list, singlyLinkedList* toRemove);

#endif // __SINGLY_LINKED_LIST_H__
