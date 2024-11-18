#include <stdio.h>
#include <stdlib.h>

typedef struct BST bst_t;
struct BST {
  int value;

  bst_t *left;
  bst_t *right;
};


bst_t *createNode(int data){
  bst_t *newNode = (bst_t*)malloc(sizeof(bst_t));
  newNode->value = data;
  newNode->left = newNode->right = NULL;

  return newNode;
}

bst_t *insertChild(bst_t *root, int data){
  bst_t *node = createNode(data);

  if (root == NULL)
  {
    return node;
  }

  if(root->value == data){
    return root;
  }


  if (root->value < data){
    root->right = insertChild(root->right,data);
  }

  else{
    root->left =insertChild(root->left,data);
  }

  return root;
}

int searchNode(bst_t *root, int data){
  int left = 0,right= 0;

  if (root == NULL)
  {
    return 0;
  }

  if(root->value == data){
    return 1; //return tree
  }

  if (root->value < data){
    right =  searchNode(root->right,data);
    //return s....
  }

  else{
    left =  searchNode(root->left,data);
  }

  return left || right;
}

void DFS_InOrder(bst_t *tree){

  if(tree == NULL){
    return ;
  }

  DFS_InOrder(tree->left),
  printf("%d\n",tree->value);
  DFS_InOrder(tree->right);
}

void main(){
  bst_t *root = createNode(5);

  root = insertChild(root,3);
  root = insertChild(root,6);
  root = insertChild(root,2);

  DFS_InOrder(root);

  printf("\n");

  if (searchNode(root,0) == 1 )
  {
    printf("found node!");
  }

}
