/*

  MemoryManager.c

  Gehrig Wilcox <lougehrig10@gmail.com>

  3/9/21

*/

#include "DataStructures/LinkedList/DoublyLinkedList.h"


typedef struct {
  doublyLinkedList_t list;
  int size;
} freeMemory_t;

doublyLinkedList_t* freeMemoryList;


/*

  Returns true if pointer is found somewhere in the freeMemoryList

*/
boolean isInFreeMemoryList(void* pointer){
  freeMemory_t* lookingAt = (freeMemory_t*)freeMemoryList;
  // While we havent found what we are looking for, and we havent made a loop
  while(!lookingAt==pointer&&!lookingAt==freeMemoryList->prev){
    // Look at the next element
    lookingAt=lookingAt->list->next;
  }
  // Return whether or not we have found what we are looking for
  return lookingAt==pointer;
}
/*

  Verify that given pointer is freed memory. If the given pointer has a size
  element that when the pointer is offset by, points back to the pointer
  (i.e. The pointer looks like a valid freeMemory), and we find it in the
  freeMemoryList, it is free memory and we return true.

*/
boolean isFreeMemory(void* pointer){

  freeMemory_t* possibleFreeMemory = (freeMemory_t*) pointer;

  /*

    Return whether or not the pointer at the end of the memory block points back
    to the beginning of the memory block.

    Also, make sure memory block is in freeMemoryList

  */
  return
  (((freeMemory_t*)(possibleFreeMemory+possibleFreeMemory->size))==possibleFreeMemory)
  &&
  isInFreeMemoryList(possibleFreeMemory);
}
/*

  Adds freeMemory to freeMemoryList, in order from greatest to least memory size

*/
void addToFreeMemoryList(freeMemory_t* freeMemory){
  freeMemory_t* lookingAt = (freeMemory_t*)freeMemoryList;

  // While the current elements size is larger than the freeMemory size
  while(lookingAt->size>freeMemory->size){
    // Look at next element
    lookingAt=lookingAt->list->next;
    // If we have made a loop, then stop looking
    if(lookingAt==freeMemoryList)break;
  }
  // Place freeMemory at current spot
  placeInDoublyLinkedList(freeMemoryList,lookingAt->list->prev);
}
/*

  Prepare all memory to be ready for allocation

*/
void initMemory(){

}

/*
  Request for a memory block to be reserved
*/
void allocateMemory(){

}

/*

  Allow given memory to be allocated elsewhere

*/
void freeMemory(void* memory, int sizeToFree){

  freeMemory_t* freedMemory = (freeMemory_t*)memory;

  // Set freed memory size to the size we want to free
  freedMemory->size=sizeToFree;

  // Point to wherever above pointer points to
  freeMemory_t* possibleFreeMemory = ((freeMemory_t*)freedMemory-sizeof(freeMemory_t*));

  /*

    Verify that above memory is free. If the above pointer points to a location
    who has an integer value where size is located in the freeMemory_t structure
    that will offset its memory location back to the end (i.e. if the above
    memory has the valid structure of a freed memory) then search for it in the
    freeMemoryList. If found, then it is free and combine with

  */
  if(isFreeMemory(possibleFreeMemory)){
      // Set new freeMemory header
      freedMemory = possibleFreeMemory;
      // Add memory to free memory
      freedMemory->size+=sizeToFree;
      // Remove memory from free memory list, to be reorganized
      removeFromDoublyLinkedList(freeMemoryList,freedMemory);
  }

  possibleFreeMemory = ((freeMemory_t*)freedMemory+freedMemory->size+1);

  if(isFreeMemory(possibleFreeMemory)){
    // Add memory to free memory
    freedMemory->size+=possibleFreeMemory->size;
    // Remove memory from free memory list, to be reorganized
    removeFromDoublyLinkedList(freeMemoryList,possibleFreeMemory);
  }

  // Make the last bit of memory point to the freeMemory data
  ((freeMemory_t*)freedMemory+sizeToFree-sizeof(freeMemory_t*))=freedMemory;

  // Place newly freed memory in freeMemoryList
  addToFreeMemoryList(freedMemory);

}
