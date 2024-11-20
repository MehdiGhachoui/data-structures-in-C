#include <stdio.h>
#include <stdlib.h>

typedef struct Heap heap_t;
struct Heap{
  int capacity;
  int size;
  int *arr;
};

void swap(int* a, int* b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

insertValue(heap_t *heap,int data){

  if(heap->capacity == heap->size){
    printf("Heap Overflow\n");
    return ;
  }

  int i = heap->size;
  heap->arr[heap->size++] = data;

  while (i != 0 && heap->arr[(i - 1) / 2] < heap->arr[i]) {
    swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
    i = (i - 1) / 2;
  }
}

void main(){
  heap_t *heap = (heap_t*)malloc(sizeof(heap_t));
  heap->capacity = 10;
  heap->size = 0;
  heap->arr = (int*)malloc(heap->capacity * sizeof(int));

}
