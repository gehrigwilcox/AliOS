/*

  DoublyLinkedList.h

  Gehrig Wilcox <lougehrig10@gmail.com>

  3/9/21

*/

#ifndef __DOUBLY_LINKED_LIST_H__
#define __DOUBLY_LINKED_LIST_H__

typedef struct {
  void* prev;
  void* next;
} doublyLinkedList_t;

/*

  Places toAppend at the end of list

*/
void appendToDoublyLinkedList(doublyLinkedList_t* list, doublyLinkedList_t* toAppend);
/*

  Places toPlace right after element

*/
void placeInDoublyLinkedList(doublyLinkedList_t* element, doublyLinkedList_t* toPlace);
/*

  Removes toRemove from list

*/
void removeFromDoublyLinkedList(doublyLinkedList_t* list, doublyLinkedList* toRemove);

#endif // __DOUBLY_LINKED_LIST_H__
