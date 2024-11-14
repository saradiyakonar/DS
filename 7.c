#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = key;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);

    return root;
}

void inorderTraversal(struct Node* root) {
    if (root) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct Node* root) {
    if (root) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct Node* root) {
    if (root) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);
    
    return search(root->right, key);
}

int findSmallestElement(struct Node* root) {
    if(!root){
        printf("Empty\n");
        return INT_MIN;
    }
    while(root->left!=NULL){
        root = root->left;
        return root->data;
    }
}

int findLargestElement(struct Node* root) {
    if(!root){
        printf("Empty\n");
        return INT_MAX;
    }
    while(root->right!=NULL){
        root = root -> right;
        return root->data;
    }
}

void deleteTree(struct Node* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        free(root);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, key;

    do {
        printf("\n:Binary Search Tree Menu:\n");
        printf("\n0. Quit\n1. Create\n2. In-order Traversal\n3. Pre-order Traversal\n4. Post-order Traversal\n5. Search\n6. Find Smallest Element\n7. Find Largest Element\n8. Deletion of Tree\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                deleteTree(root);
                exit(0);
            case 1:
                printf("Enter a value to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 2:
                printf("In-order Traversal: ");
                inorderTraversal(root);
                break;
            case 3:
                printf("Pre-order Traversal: ");
                preorderTraversal(root);
                break;
            case 4:
                printf("Post-order Traversal: ");
                postorderTraversal(root);
                break;
            case 5:
                printf("Enter a value to search: ");
                scanf("%d", &key);
                if (search(root, key))
                    printf("Key found!\n");
                else
                    printf("Key not found.\n");
                break;
            case 6:
                printf("Smallest Element is: %d\n", findSmallestElement(root));
                break;
            case 7:
                printf("Largest Element is: %d\n", findLargestElement(root));
                break;
            case 8:
                deleteTree(root);
                root = NULL;
                break;
            default:
                printf("Invalid\n");
        }
    } while (choice != 0);

    return 0;
}