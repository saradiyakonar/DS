#include<stdlib.h>
#include<stdio.h>
#include<limits.h>

struct node
{
  struct node * left;
  int data;
  struct node * right;
};

struct node *new_node(int x)
{
    struct node *temp;
    temp = malloc(sizeof(struct node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
struct node *insert(struct node *root, int x)
{
    if (root == NULL)
        return new_node(x);
    else if (x > root->data)
        root->right = insert(root->right, x);
    else
        root->left = insert(root->left, x);
    return root;
}

void deleteTree(struct node * rootPtr)
{
    if (rootPtr)
    {
        deleteTree(rootPtr->left);
        deleteTree(rootPtr->right);
        free(rootPtr);
    }
}
int sumOfNodes(struct node *rootptr)
{
    if (rootptr == NULL)
    {
        return 0;
    }
    int leftSum = sumOfNodes(rootptr->left);
    int rightSum = sumOfNodes(rootptr->right);
    int sum = leftSum + rightSum + rootptr->data;
    return sum;
}
struct node *search(struct node *rootPtr, int x)
{
    if (rootPtr == NULL || rootPtr->data == x)
        return rootPtr;
    else if (x > rootPtr->data)
        return search(rootPtr->right, x);
    else
        return search(rootPtr->left, x);
}
struct node* max(struct node *rtemp){
    struct node *current=rtemp;
    while(current->right!=NULL){
        current=current->right;
    }
    return current;
}
struct node *min(struct node *rtemp){
    struct node *current=rtemp;
    while(current->left!=NULL){
        current=current->left;
    }
    return current;
}

void print_preorder(struct node * rootPtr)
{
    if (rootPtr)
    {
        printf("%d\n",rootPtr->data);
        print_preorder(rootPtr->left);
        print_preorder(rootPtr->right);
    }
}

void print_inorder(struct node * rootPtr)
{
    if (rootPtr)
    {
        print_inorder(rootPtr->left);
        printf("%d\n",rootPtr->data);
        print_inorder(rootPtr->right);
    }
}

void print_postorder(struct node * rootPtr)
{
    if (rootPtr)
    {
        print_postorder(rootPtr->left);
        print_postorder(rootPtr->right);
        printf("%d\n",rootPtr->data);
    }
}
int noofleafnodes(struct node * rootptr){
    static int count = 0;
    if (rootptr != NULL)
    {
        noofleafnodes(rootptr->left);
        if ((rootptr->left == NULL) && (rootptr->right == NULL))
        {
            count++;
        }
        noofleafnodes(rootptr->right);
    }
    return count;
    
}
int Nonleaf(struct node *rootptr)
{
    if (rootptr == NULL || (rootptr->left == NULL && rootptr->right == NULL))
    {
        return 0;
    }
    int non_leaf = 1 + Nonleaf(rootptr->left) + Nonleaf(rootptr->right);
    return non_leaf;
}
int totalNodes(struct node *rootptr)
{
    if (rootptr == NULL)
        return 0;
    int l = totalNodes(rootptr->left);
    int r = totalNodes(rootptr->right);
    int total = 1 + l + r;
    return total;
}
int Depth(struct node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int lDepth = Depth(node->left);
        int rDepth = Depth(node->right);
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

struct node* deleteNode(struct node* root, int key)
{

    if (root == NULL){
        return root;
    }
 
    if (key < root->data)
        root->left = deleteNode(root->left, key);
 
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
 
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
 
        struct node* temp = min(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}


int main()
{   
    
    int val9;
    struct node *root = NULL;
    struct node *tmp = NULL;
    printf("the menu choice\n");
    printf("0. Quit\n");
    printf("1. Create\n");
    printf("2. In-order Traversal\n");
    printf("3. Pre-order Traversal\n");
    printf("4. Post-order traversal\n");
    printf("5. Search\n");
    printf("6. Find Smallest Element\n");
    printf("7. Find Largest Element\n");
    printf("8. Deletion of Tree\n");
    printf("9. To count number of leaf nodes in the tree.\n");
    printf("10. To count number of non leaf nodes in the tree.\n");
    printf("11. To find number of nodes in the tree.\n");
    printf("12. To find sum of all nodes of the tree.\n");
    printf("13. To print depth of the tree.\n");
    printf("14. To find nodes which are at maximum depth in the tree.\n");
    printf("15. delete the node \n");
    while(1){
        int choice;
        printf("enter your choice");
        scanf("%d",&choice);
        switch(choice){
            case 0:{
                exit(0);
            break;
            }
            case 1:{
             root = new_node(20);
            insert(root, 5);
            insert(root, 1);
            insert(root, 15);
            insert(root, 9);
            insert(root, 7);
            insert(root, 12);
            insert(root, 30);
            insert(root, 25);
            insert(root, 40);
            insert(root, 45);
            insert(root, 42);
            break;
            }
            case 2:{
                print_inorder(root);
            break;
            }
            case 3:{
                print_preorder(root);
            break;
            }
            case 4:{
                print_postorder(root);
            break;
            }
            case 5:{
                int val;
                printf("Enter value you want to search for:");
               scanf("%d", &val);
               search(root, val);
               break;
            }
            case 6:{
                struct node *minVal=min(root);
                printf("%d\n",minVal->data);
            break;
            }
            case 7:{
                struct node *maxVal=max(root);
                printf("%d\n",maxVal->data);
            break;
            }
            case 8:{
                deleteTree(root);
            break;
            }
            case 9:{
                printf("The total number of leaf nodes is %d\n", noofleafnodes(root));
            break;
            }
            case 10:{
                printf("The total number of non-leaf nodes is %d\n", Nonleaf(root));
                break;
            }
            case 11:{
                printf("The total number of  nodes is %d\n", totalNodes(root));
                break;
            }
            case 12:{
                printf("The sum of nodes is %d\n", sumOfNodes(root));
                break;
            }
            case 13:{
                printf("The depth of the tree is %d\n", Depth(root));
                break;
            }
            case 14:{
                int key;
                printf("enter the node to be deleted\n");
                scanf("%d",&key);
                deleteNode(root,key);
                print_inorder(root);
                break;
            }
        }
    }
    return 0;
}