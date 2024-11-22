#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Heap heap_t;
struct Heap{
  int capacity;
  int size;
  int *arr;
};

// MAX HEAP;

void swap(int* a, int* b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void updateHeap(heap_t *heap,int i){
  int current = i;
  int leftChild = 2*i + 1;
  int rightChild = 2*i + 2;


  if(leftChild<heap->size && heap->arr[leftChild]>heap->arr[current]){
    current = leftChild;
  }
  if(rightChild<heap->size && heap->arr[rightChild]>heap->arr[current]){
    current = rightChild;
  }

  if(i!=current){
    swap(&heap->arr[i],&heap->arr[current]);
    updateHeap(heap,current);
  }
  return;
}

void insertValue(heap_t *heap,int data){
  assert(heap->size != heap->capacity && "Reached Heap Maximum Capacity");

  int i = heap->size;
  heap->arr[heap->size++] = data;

  while (i!=0 && heap->arr[(i-1)/2]<heap->arr[i])
  {
    swap(&heap->arr[(i-1)/2],&heap->arr[i]);
    i = (i-1)/2; //next parent
  }

  return;
}

void deleteValue(heap_t *heap,int index){

  assert(index >= heap->size && "Index out of scope");

  if(index == heap->size - 1){
    heap->size--;
    return;
  }

  heap->arr[index] = heap->arr[heap->size - 1];
  heap->size--;

  updateHeap(heap,index);
  return;
}

int extractMax(heap_t *heap){

  assert(heap->size == 0 && "Extraction On Empty Heap");

  if (heap->size == 1)
  {
    heap->size--;
    return heap->arr[0];
  }


  int max = heap->arr[0];

  heap->arr[0] = heap->arr[heap->size - 1];
  heap->size--;

  updateHeap(heap,0);
  return max;
}

void main(){
  heap_t heap;
  heap.capacity = 10;
  heap.size = 0;
  heap.arr = malloc(heap.capacity * sizeof(int));


}
