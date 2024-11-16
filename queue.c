#include <stdio.h>
#include <stdlib.h>

typedef struct Node node_t;
struct Node
{
  int value;
  node_t *next;
};

typedef struct Queue
{
  node_t *head;  //node representing the head of the queue
  node_t *tail; //node representing the tail of the queue
} queue_t;

// ADD A TAIL
void enQueue(queue_t *queue, int number){
  node_t *newNode = (node_t*)malloc(sizeof(node_t));
  newNode->value = number;
  newNode->next = NULL;

  //Queue Empty
  if(queue->head == NULL && queue->tail == NULL){
    queue->head = queue->tail = newNode;
  }

  queue->tail->next = newNode;
  queue->tail = newNode;
}

// POP THE HEAD
int deQueue(queue_t *queue){

  // Queue Empty
  if(queue->head == NULL && queue->tail == NULL){
    printf("Queue Empty");
    return -1;
  }

  node_t *node = queue->head;
  int data = node->value;

  queue->head = queue->head->next;

  // Queue Empty
  if(queue->head == NULL){
    queue->tail = NULL;
  }

  free(node);
  return data;
}

void main(){
  queue_t *queue = (queue_t*)malloc(sizeof(queue_t));
  queue->head = queue->tail = NULL;

  enQueue(queue,0);
  enQueue(queue,1);
  int data = deQueue(queue);

  node_t *node = queue->head;
  while (node != NULL)
  {
    printf("%d",node->value);
    free(node);
    node = node->next;
  }

  free(queue->head);
  free(queue->tail);
}
