#include <stdio.h>
#include "tests.h"
#include "genericLinkedList.h"

void runTests(){
  printf("Tests running...\n");
  
  listElement* list = createEl("First String (1)", 30, printString);
  
  addEl(list, "Second String (2)", 30, printString);

  int int_el = 18;

  addEl(list, &int_el, sizeof(int), printNumber);

  char char_el = '?';

  addEl(list, &char_el, sizeof(char), printChar);

  int a = 30;

  listElement* list2 = createEl(
	  &a,
	  sizeof(int),
	  printNumber
  );
  printf("list: \n");

  traverse(list);

  printf("reverse list: \n");
  reverse(&list);
  traverse(list);

  printf("\nTests complete.\n");
}
