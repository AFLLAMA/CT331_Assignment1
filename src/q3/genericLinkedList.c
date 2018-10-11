#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listElementStruct {
	void* data;
	size_t size;
	struct listElementStruct* next;
	void(*fun)(void *);
} listElement;

listElement* createEl(void* data, size_t size, void(*fptr)(void *)) {
	listElement* e = malloc(sizeof(listElement));
	if (e == NULL) {
		return NULL;
	}
	e->data = malloc(size);
	
	memmove(e->data, data, size);

	e->size = size;
	e->next = NULL;
	e->fun = fptr;
	return e;
}

void traverse(listElement* list) {

	listElement* current = list;
	while (current != NULL) {
		(*current->fun)(current->data);
		current = current->next;
	}
	printf("\n");
}

void printNumber(void *n) {
	printf("%d\n", *(int *)n);
}

void printChar(void *ch) {
	printf("%c\n", *(char *)ch);
}

void printString(void *c) {
	printf("%s\n", (char *)c);
}

void addEl(listElement* list, void* data, size_t size, void(*fptr)(void *)) {

	listElement* current = list;

	listElement* newNode = createEl(data, size, fptr);

	while (current->next != NULL) {
		current = current->next;
	}

	current->next = newNode;

}

void reverse(listElement** list) {
	listElement* prev = NULL;
	listElement* curr = *list;
	listElement* next = NULL;

	while (curr != NULL)
	{
		next = curr->next;
		
		curr->next = prev;

		prev = curr;
		curr = next;
	}
	*list = prev;
}