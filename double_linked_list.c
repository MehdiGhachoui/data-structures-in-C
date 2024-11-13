#include <stdio.h>
#include <stdlib.h>

typedef struct List dll_t;
struct List {
  int value;
  dll_t *prev;
  dll_t *next;
} ;

//insert to head
dll_t *appendToHead(dll_t *nodeList, int number){
  dll_t *newHead = (dll_t*)malloc(sizeof(dll_t));
  newHead->prev = NULL;
  newHead->next = nodeList;
  newHead->value = number;

  return newHead;
}

//insert to tail
dll_t *appendToTail(dll_t *nodeList, int number){
  dll_t *newTail = (dll_t*)malloc(sizeof(dll_t));
  newTail->prev = NULL;
  newTail->next = NULL;
  newTail->value = number;

  if (nodeList == NULL)
  {
    return newTail;
  }

  dll_t *current = nodeList;
  while (current->next != NULL)//before last element
  {
    current = current->next;
  }
  newTail->prev=current;
  current->next = newTail;

  return nodeList;
}

//insert to position
dll_t *appendToPosition(dll_t *nodeList,int position, int number){
  dll_t *newNode = (dll_t*)malloc(sizeof(dll_t));
  newNode->prev = NULL;
  newNode->next = NULL;
  newNode->value = number;

  if (nodeList == NULL)
  {
    return newNode;
  }

  dll_t *current = nodeList;
  int iterator = 1;
  while(position-1 != iterator &&  current!= NULL)
  {
    current = current->next;
    iterator++;
  }

  if(current == NULL){
    printf("Position %d is out of scope",position);
    free(newNode);
  }

  newNode->prev = current;
  newNode->next = current->next;
  current->next = newNode;

  return nodeList;
}

void main(){
  dll_t *Node = (dll_t*)malloc(sizeof(dll_t));
  Node->prev=NULL;
  Node->next=NULL;
  Node->value=1;

  Node = appendToHead(Node,0);
  Node = appendToTail(Node,3);
  Node = appendToPosition(Node,3,2);

  while (Node != NULL)
  {
    printf("%d\n",Node->value);
    free(Node);
    Node = Node->next;
  }


}
