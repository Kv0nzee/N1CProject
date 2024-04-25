#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Malloc Failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else if (root->data > data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void inorder(struct Node* root, int depth){
    if(root != NULL){
        inorder(root->right, depth + 1); // Visit right subtree first for better visualization
        for(int i = 0; i < depth; i++) {
            printf("   "); // Print indentation based on depth
        }
        printf("%d\n", root->data); // Print the current node's data
        inorder(root->left, depth + 1); // Visit left subtree
    }
}

struct Node* findMin(struct Node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

struct Node* deleteNode(struct Node* root, int data){
    if(root == NULL){
        return root;
    }

    if(root->data > data){
        root->left = deleteNode(root->left, data);
    }else if(root->data < data){
        root->right = deleteNode(root->right, data);
    }else{
        if(root->left == NULL){
            struct Node* temp = root->right;
            free(root);
            return  temp;
        }else if(root->right == NULL){
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findMin(root->right);
        root->data = temp->data;

        root->right =deleteNode(root->right,temp->data);
    }

    return root;

}

struct Node* findData(struct Node* root, int data){
    if(root == NULL || data == root->data){
        return root;
    }

    if(root->data > data){
        return findData(root->left, data);
    }

    return findData(root->right, data);
}

int main() {
    struct Node* root = NULL;

    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 15);
    root = insertNode(root, 20);
    root = insertNode(root, 3);
    root = insertNode(root, 8);
    root = insertNode(root, 13);
    inorder(root, 0);
    root = deleteNode(root,110);
    inorder(root, 0);

    struct Node* result = findData(root, 113);
    if (result != NULL) {
        printf("Value found in the tree!\n");
    } else {
        printf("Value not found in the tree.\n");
    }

    return 0;
}
