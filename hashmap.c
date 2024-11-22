#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#define MAX_SIZE 10

typedef struct HT_Item{
  char *key;
  char *value;
}ht_item_t;

ht_item_t *newItem(char *k,char *v){
  ht_item_t *item = malloc(sizeof(ht_item_t));
  item->key = strdup(k);
  item->value = strdup(v);

  return item;
}

void insertItem(ht_item_t *item){
  ht_item_t *item = malloc(sizeof(ht_item_t))
}


//hash function:
// Given a key return and index between 0 and size-1 ?
// beware of collisions (returning the same index for a key)
int hashFunction(char *key){

}

void main(){
  ht_item_t *arr[MAX_SIZE];




  return;
}
