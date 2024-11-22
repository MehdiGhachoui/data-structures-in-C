#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct stack stack_t;
struct stack
{
  int position;
  int arr[MAX_SIZE];
};

int isFull(stack_t *stk){
  return stk->position == MAX_SIZE -1;
}

int isEmpty(stack_t *stk){
  return stk->position == -1;
}

void  pushToStack(stack_t *stk,int value){

  if (isFull(stk))
  {
    printf("Stack Limit error");
    exit(1);
  }

  stk->position++;
  stk->arr[stk->position] = value;
}

int popFromStack(stack_t *stk){

  if(isEmpty(stk)){
    printf("Stack Empty error");
    exit(1);
  }

  int value = stk->arr[stk->position];
  stk->position--;

  return value;
}

int peekTop(stack_t *stk){
  return stk->arr[stk->position];
}

void main(){
  stack_t newStack;
  newStack.position = -1;

  int userVal;
  while (!isFull(&newStack))
  {
    printf("insert new value:");
    scanf("%d",&userVal);

    pushToStack(&newStack,userVal);
  }

  printf("\n\n%d\n\n",peekTop(&newStack));

  while (!isEmpty(&newStack))
  {
    int value = popFromStack(&newStack);
    printf("%d\n",value);
  }
}
