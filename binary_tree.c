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

// II - BFS : Exploring all nodes on each level before going down (using a Queue) -left then right-
void BFS_Order(bt_t *tree){

  if(tree == NULL){
    return ;
  }

  bt_t *queue[100];
  int front = 0 , rear = 0;
  queue[rear++] = tree;

  while (front<rear)
  {
    bt_t *node = queue[front++];

    printf("%d",node->value);

    if (node->left)
    {
      queue[rear++] = node->left;
    }
    if (node->right)
    {
      queue[rear++] = node->right;
    }

  }
}


// Insertion: starts with the left
bt_t *insertChild(bt_t *tree,int data){
  bt_t *newNode = create_node(data);

  if (tree == NULL)
  {
    return newNode;
  }

  bt_t *queue[100];
  int front = 0, rear = 0;

  queue[rear++] = tree;

  while (front<rear)
  {
    bt_t *node = queue[front++];

    if (node->left)
    {
      queue[rear++]= node->left;
    }
    else{
      node->left = newNode;
      break;
    }

    if (node->right)
    {
      queue[rear++]= node->right;
    }
    else{
      node->right = newNode;
      break;
    }

  }
  return tree;
}


// Search : in case of normal BT (!BST) we use the traversal functions
int searchNode(bt_t *tree, int data){
  if (tree == NULL)
  {
    return 0;
  }

  if (tree->value == data)
  {
   return 1 ;
  }

  int left = searchNode(tree->left,data);
  int right = searchNode(tree->right,data);

  return left || right;
}


void main(){
  bt_t *root = create_node(1);
  bt_t *first_child = create_node(2);
  bt_t *second_child = create_node(3);

  root->left = second_child;
  root->right = first_child;
  root = insertChild(root,4);
  root = insertChild(root,5);

  DFS_PreOrder(root);
  printf("\n");
  DFS_InOrder(root);
  printf("\n");
  DFS_PostOrder(root);
  printf("\n");
  printf("\n");
  BFS_Order(root);

  printf("\n");

  if(searchNode(root,4) == 1){
    printf("found!");
  }

}
