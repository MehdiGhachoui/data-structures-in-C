#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#define INIT_CAPACITY 10

typedef struct {
  char *key;
  char *value;
}ht_item;

typedef struct {
  int capacity;
  int size;
  ht_item **items;
}ht;

//hash function:
// Given a key return and index between 0 and size-1 ?
// beware of collisions (returning the same index for a key)
int hashFunction(char *key){
  unsigned long hash = 0;

  for (int j = 0; key[j]; j++){
    hash += key[j];
  }

  return hash % INIT_CAPACITY;
}

ht_item *newItem(char *k,char *v){
  ht_item *item = malloc(sizeof(ht_item)); //the actual object

  assert(item != NULL && "Failed to allocate a new item");

  item->key = strdup(k);
  item->value = strdup(v);

  return item;
}

void freeItem(ht_item *item){
  free(item->key);
  free(item->value);
  free(item);

  return;
}

ht *newMap(){
  ht *map = malloc(sizeof(ht));
  assert(map != NULL && "Failed to allocate a new map");

  map->capacity = INIT_CAPACITY;
  map->size = 0;

  //calloc(map->capacity, sizeof(void*)); ...why?
  //The struct here doesn't matter , since the the value of each field is an address
  //The size of a pointer is independent of the type it points to.
  //void* == Type*; **on most systems**
  map->items = calloc(map->capacity, sizeof(ht_item*));// the pointer to the object

}


void freeMap(ht *map){
  int i = 0;
  while (i<map->size)
  {
    if(map->items[i] != NULL){
      freeItem(map->items[i]);
    }
    i++;
  }
  free(map->items);
  free(map);
}

void insetItem(ht *map,char *k, char *v){
  assert(map->size != map->capacity && "Reached Maximum capacity of the map");

  ht_item *item = newItem(k,v);
  int index = hashFunction(k);

  map->items[index] = item;
  map->size++;

  return;
}

char *searchItem(ht *map, char *key){
  int index = hashFunction(key);
  ht_item *item =  map->items[index];

  if(item == NULL){
    printf("Item does not exist\n");
    return NULL;
  }

  if(strcmp(item->key,key) == 0){
    return item->value;
  }

  return NULL;
}

void removeItem(ht *map,char *key){
  int index = hashFunction(key);
  ht_item *item = map->items[index];

  freeItem(item);
  map->items[index] = NULL;

  map->size--;

  return;
}

void main(){
  ht *map = newMap();
  insetItem(map,"kt","Hello");
  insetItem(map,"kw","world");

  printf("test 2: %s\n",searchItem(map,"kw"));
  printf("test 1: %s\n",searchItem(map,"kt"));
  printf("map size: %d\n\n",map->size);

  removeItem(map,"kt");
  removeItem(map,"kw");

  printf("test 1: %s\n",searchItem(map,"kw"));
  printf("test 2: %s\n",searchItem(map,"kt"));
  printf("map size: %d",map->size);

  freeMap(map);
  return;
}
