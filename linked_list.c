#include <stdio.h>
#include <stdlib.h>

typedef struct List list_t;
struct List {
  int value;
  list_t *next;
};

void next(list_t* list){
  list = list->next;
};

list_t *append(int number){
  list_t *newList = (list_t*)malloc(sizeof(list_t));

  newList->value = number;
  newList-> next = NULL;

  return newList;
};

//Implement Indexing!?
void  main(){
  list_t *list = (list_t*)malloc(sizeof(list_t));
  list->value = 5;
  list->next = NULL;

  printf("%d",list->value);
  list = append(4);
  next(list);
  printf("%d",list->value);

  // free each pointer
  while(list != NULL){
    free(list);
    next(list);
  };
}
