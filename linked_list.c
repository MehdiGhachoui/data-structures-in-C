#include <stdio.h>
#include <stdlib.h>

typedef struct List list_t;
struct List {
  int value;
  list_t* next;
};

void printList(list_t* list){
  list_t* current = list;
  while (current != NULL){
    printf("%d\n",current->value);
    current = current->next;
  }
};

list_t* appendToTail(int number,list_t* list){
  list_t* newTail = (list_t*)malloc(sizeof(list_t));
  newTail->value = number;
  newTail-> next = NULL;

  list_t* temp = list;
  while (temp->next != NULL)
  {
    temp = temp->next;
  };

  temp->next = newTail;
  return list;
};

list_t* appendToHead(int number, list_t* list){
  list_t* newHead = (list_t*)malloc(sizeof(list_t));
  newHead->value = number;
  newHead->next = list ;

  return newHead;
};

list_t* appendToPosition(int number,int position, list_t* list){
  list_t* node = (list_t*)malloc(sizeof(list_t));
  node->value = number;
  node->next = NULL;

  if (position == 1)
  {
    node->next = list;
    list = node;
    return list;
  }

  list_t* current = list;
  int iterator = 1;
  while (position - 1 != iterator && current != NULL)
  {
    current = current->next;
    iterator++;
  };

  if(current == NULL){
    printf("Position %d is out of bound", position);
    free(node);
    return list;
  }
  node->next = current->next;
  current->next = node;

  return list;
};

void  main(){
  list_t *list = (list_t*)malloc(sizeof(list_t));
  list->value = 1;
  list->next = NULL;

  list = appendToTail(0,list);
  list = appendToHead(3,list);
  list = appendToPosition(2,2,list);
  printList(list);

  // free each pointer
  while(list != NULL){
    free(list);
    list = list->next;
  };
}
