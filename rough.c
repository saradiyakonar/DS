#include<stdlib.h>
#include<stdio.h>

/* node declaration */
struct node
{
  struct node * left;
  int data;
  struct node * right;
};

/* code for node insertion */
struct node* insert(struct node* root, int key)
{
   if(root == NULL){
    struct node* newNode = (struct node*) malloc (sizeof(struct node*))
    newNode -> data = key ;
    newNode -> left = newNode -> right = NULL;
    return newNode;
   }

   if(key < root -> data){
    root -> left = insert(root->left,key);
   }
   else if (key > root -> data){
    root -> right = insert (root->right,key);
   }

   return root;
}

/* code for tree deletion */
void deleteTree(struct node * rootPtr)
{
    if (rootPtr)
    {
        deleteTree(rootPtr->left);
        deleteTree(rootPtr->right);
        free(rootPtr);
    }
}

/* code for node search */
struct node* search(struct node * rootPtr, int val)
{
    if(!rootPtr)
    {
        return NULL;
    }

    if (rootPtr->data == val)
    {
        return rootPtr;
    }

    if (search(rootPtr->left, val) == NULL)
      return search(rootPtr->right, val);
    else
      return rootPtr;
}

/* code for preorder traversal */
void print_preorder(struct node * rootPtr)
{
    if (rootPtr)
    {
        printf("%d\n",rootPtr->data);
        print_preorder(rootPtr->left);
        print_preorder(rootPtr->right);
    }
}

/* code for inorder traversal */
void print_inorder(struct node * rootPtr)
{
    if (rootPtr)
    {
        print_inorder(rootPtr->left);
        printf("%d\n",rootPtr->data);
        print_inorder(rootPtr->right);
    }
}

/* code for postorder traversal */
void print_postorder(struct node * rootPtr)
{
    if (rootPtr)
    {
        print_postorder(rootPtr->left);
        print_postorder(rootPtr->right);
        printf("%d\n",rootPtr->data);
    }
}

int max(struct node* rootptr){
    if(!rootptr){
        printf("Empty");
        return NULL;
    }
    while(rootptr -> right!=NULL){
        rootptr = rootptr -> right;
        return rootptr -> data;
    }
}

int min(struct node* rootptr){
     if(!rootptr){
        printf("Empty");
        return NULL;
    }
    while(rootptr -> left!=NULL){
        rootptr = rootptr -> left;
        return rootptr -> left;
    }
}

int main(){
    int choice;
    printf("1.Create\n");
    printf("2. Inorder Traversal\n");
    printf("3.Preorder Traversal\n");
    printf("4.Postorder Traversal\n");
    printf("5.Search\n");
    printf("6.Smallest Element\n");
    printf("7.Largest Element\n");
    printf("8.Delete\n");
    printf("9.Quit\n");
    
    while(1){
        printf("Enter your choice\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            root = insertNewNode(10);
            root->left = insertNewNode(7);
            root->left->right = insertNewNode(8);
            root->right = insertNewNode(6);
            root->right->left = insertNewNode(12);
            root->left ->left = insertNewNode(2);
            root->right->right = insertNewNode(17);
        }
    }

}