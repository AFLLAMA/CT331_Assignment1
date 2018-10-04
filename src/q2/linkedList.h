#ifndef CT331_ASSIGNMENT_LINKED_LIST
#define CT331_ASSIGNMENT_LINKED_LIST

typedef struct listElementStruct listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(char* data, size_t size);

//Prints out each element in the list
void traverse(listElement* start);

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* after, char* data, size_t size);

//Pushs new list element into the head of linked list
void push(listElement** after, char* data, size_t size);

listElement* pop(listElement** list);

//Delete the element after the given el
void deleteAfter(listElement* after);

//Returns length
int length(listElement* list);

//The same as push
void enqueue(listElement** list, char* data, size_t size);

//Dequeue el from the tail
listElement* dequeue(listElement* list);
#endif
