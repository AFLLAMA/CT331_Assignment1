#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

typedef struct listElementStruct{
  char* data;
  size_t size;
  struct listElementStruct* next;
} listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(char* data, size_t size){
  listElement* e = malloc(sizeof(listElement));
  if(e == NULL){
    //malloc has had an error
    return NULL; //return NULL to indicate an error.
  }
  char* dataPointer = malloc(sizeof(char)*size);
  if(dataPointer == NULL){
    //malloc has had an error
    free(e); //release the previously allocated memory
    return NULL; //return NULL to indicate an error.
  }
  strcpy(dataPointer, data);
  e->data = dataPointer;
  e->size = size;
  e->next = NULL;
  return e;
}


//Prints out each element in the list
void traverse(listElement* start){
  listElement* current = start;
  while(current != NULL){
    printf("%s\n", current->data);
    current = current->next;
  }
}

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* el, char* data, size_t size){
  listElement* newEl = createEl(data, size);
  newEl->next = el->next;
  el->next = newEl;
  return newEl;
}


//Delete the element after the given el
void deleteAfter(listElement* after){
  listElement* delete = after->next;
  listElement* newNext = delete->next;
  after->next = newNext;
  //need to free the memory because we used malloc
  free(delete->data);
  free(delete);
}
int length(listElement* list) {
	listElement* current = list;
	int len = 0;
	while (current != NULL) {
		len = len+1;
		current = current->next;
	}
	return len;
}
void swap(listElement* x, listElement* y) {
	listElement temp = *x;
	*x = *y;
	*y = temp;

}
void push(listElement** list, char* data, size_t size) {
	listElement* el1 = createEl(data,size);
	el1->next = (*list);
	swap((*list), el1);
	(*list)->next = el1;
}

listElement* pop(listElement** list) {
	if (list == NULL)
	{
		return NULL;
	}
	listElement* el1 = (*list)->next;
	(*list)->next = 0;

	listElement* popped = (*list);
	(*list) = el1;
	return popped;
}
void enqueue(listElement** list, char* data, size_t size) {
	push(list, data, size);
}
listElement* dequeue(listElement* list) {	listElement* current = list;	if (list->next==NULL)
	{
		free(list);
		return current;
	}	while (current->next->next != NULL)
	{
		current = current->next;
	}	listElement* dequeued = current->next;	free(current->next);	current->next = NULL;	return dequeued;}

