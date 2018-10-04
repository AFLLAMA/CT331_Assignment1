#include <stdio.h>
#include "tests.h"
#include "linkedList.h"

void runTests(){
  printf("Tests running...\n");
  listElement* l = createEl("Test String (1).", 30);
  //printf("%s\n%p\n", l->data, l->next);
  //Test create and traverse
  traverse(l);
  printf("\n");

  //Test insert after
  listElement* l2 = insertAfter(l, "another string (2)", 30);
  insertAfter(l2, "a final string (3)", 30);
  traverse(l);
  printf("\n");

  //Test push
  //listElement* l3 = push(l, "newNode", 30);
  printf("push....\n");
  push(&l, "pushed string(4)", 30);
  traverse(l);
  printf("\n");

  //Pop
  printf("pop....\n");
  pop(&l);
  traverse(l);
  printf("\n");

  //Dequeue
  printf("dequeue....\n");
  dequeue(l);
  traverse(l);
  printf("\n");
  
  // Test delete after
  printf("delete....\n");
  deleteAfter(l);
  traverse(l);
  printf("\n");

  
  printf("length: %d",length(l));
  printf("\nTests complete.\n");
}
 