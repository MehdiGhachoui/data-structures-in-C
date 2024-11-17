#include <stdio.h>
#include <stdlib.h>

typedef struct binary_tree bt_t;
struct binary_tree
{
  int value;
  bt_t *right;
  bt_t *left;
};

bt_t *create_node(int data){
  bt_t *node = (bt_t*)malloc(sizeof(bt_t));
  node->value = data;
  node->left = node->right = NULL;

  return node;
}

//TREE TRAVERSAL:

//I - DFS: Go As far down as possible before backtracking (Stacks help visualizing recursion)
//1. Pre-order : current-left-right
void DFS_PreOrder(bt_t *tree){

  if(tree == NULL){
    return ;
  }

  printf("%d",tree->value);
  DFS_PreOrder(tree->left);
  DFS_PreOrder(tree->right);
}

//2. In-order : left-current-right
void DFS_InOrder(bt_t *tree){

  if(tree == NULL){
    return ;
  }

  DFS_InOrder(tree->left),
  printf("%d",tree->value);
  DFS_InOrder(tree->right);
}

//2. Post-order : left-right-current
void DFS_PostOrder(bt_t *tree){

  if(tree == NULL){
    return ;
  }

  DFS_PostOrder(tree->left),
  DFS_PostOrder(tree->right);
  printf("%d",tree->value);
}

// II - BFS : Exploring all nodes on each level before going down (using a Queue)
void BFS_Order(bt_t *tree){

  if(tree == NULL){
    return ;
  }

  bt_t *queue[100];
  int front , rear = 0;
  queue[rear] = tree;
  rear++;

  while (front<rear)
  {
    bt_t *node = queue[front];
    front++;

    printf("%d",node->value);
    if (node->left)
    {
      queue[rear] = node->left;
      rear++;
    }
    if (node->right)
    {
      queue[rear] = node->right;
      rear++;
    }

  }



  BFS_Order(tree->left);
  BFS_Order(tree->right);
}

void main(){
  bt_t *root = create_node(1);
  bt_t *first_child = create_node(2);
  bt_t *second_child = create_node(3);

  root->left = second_child;
  root->right = first_child;

  DFS_PreOrder(root);
  printf("\n");
  DFS_InOrder(root);
  printf("\n");
  DFS_PostOrder(root);
  printf("\n");
  printf("\n");
  BFS_Order(root);
}
