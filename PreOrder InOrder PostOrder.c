#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node{
    int key;
    struct Node *left, *right;
}Node;

Node *newNode (int item){
    Node *temp = (Node*) malloc(sizeof(Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

Node *insert (Node *node, int key){
    if(node == NULL)
        return newNode(key);

    if(key < node->key)
        node->left = insert(node->left, key);

        else if( key > node->key)
            node->right= insert(node->right, key);

        return node;
}

void preorder(Node *root) {
   if(root != NULL) {
	printf("%d ", root->key);
 	preorder(root->left);
	preorder(root->right);
   }
}

void inorder(Node *root) {
   if(root != NULL) {
	inorder(root->left);
	printf("%d ", root->key);
 	inorder(root->right);
   }
}

void postorder(Node *root) {
   if(root != NULL) {
	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->key);
   }
}

int main(){
    Node *root = NULL;

    root = insert(root,50);

    insert(root,50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("\nPre-Order Traversal: ");
  preorder(root);

  printf("\nIn-Order Traversal: ");
  inorder(root);

  printf("\nPost-Order Traversal: ");
  postorder(root);
  printf("\n");
    return 0;
}

