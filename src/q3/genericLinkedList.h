
typedef struct listElementStruct listElement;

listElement* createEl(void* data, size_t size, void(*fptr)(void *));

void traverse(listElement* list);

void addEl(listElement* list, void* data, size_t size, void(*fptr)(void *));

void printNumber(void *n);

void printString(void *c);

void printChar(void *ch);

void reverse(listElement** list);