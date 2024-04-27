

#ifndef C_PROGRAMMING_AVLTREE_H
#define C_PROGRAMMING_AVLTREE_H

#include <stdio.h>
#include <stdlib.h>
#include "projectHeader.h"

int getHeight(struct Db* node){
    if(node == NULL){
        return 0;
    }
    return  node->height;
}

struct Db* create(int phoneNumber){
    struct Db* node = (struct Db*) malloc(sizeof (struct Db));
    node->phoneNumber = phoneNumber;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int max(int l, int r){
    return (l>r) ? l : r;
}

int getBalanceFactor(struct Db* node){
    if(node == NULL){
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

struct Db* leftRotate(struct Db* node){
    printf("Performing Left Rotation...\n");
    printf("Before Rotation:\n");
    inorder(node, 0);

    struct Db* x = node->right;
    struct Db* t2 = x->left;

    x->left = node;
    node->right = t2;

    node->height = max(getHeight(node->right), getHeight(node->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    printf("After Rotation:\n");
    inorder(x, 0);
    return x;
}

struct Db* rightRotate(struct Db* node){
    printf("Performing Right Rotation...\n");
    printf("Before Rotation:\n");
    inorder(node, 0);

    struct Db* x = node->left;
    struct Db* t2 = x->right;

    x->right = node;
    node->left = t2;

    node->height = max(getHeight(node->right), getHeight(node->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    printf("After Rotation:\n");
    inorder(x, 0);
    return x;
}

struct Db* insertNode(struct Db* root, int phoneNumber){
    if(root == NULL)
        return create(phoneNumber);

    if(root->phoneNumber > phoneNumber)
        root->left = insertNode(root->left, phoneNumber);
    else if (root->phoneNumber < phoneNumber)
        root->right = insertNode(root->right, phoneNumber);
    else
        return root;

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    int balanceFactor = getBalanceFactor(root);

    // Left Left Case
    if(balanceFactor > 1 && phoneNumber < root->left->phoneNumber){
        return rightRotate(root);
    }
    // Right Right Case
    if(balanceFactor < -1 && phoneNumber > root->right->phoneNumber){
        return leftRotate(root);
    }
    // Left Right Case
    if(balanceFactor > 1 && phoneNumber > root->left->phoneNumber){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // Right Left Case
    if(balanceFactor < -1 && phoneNumber < root->right->phoneNumber){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root; // Return the updated root
}

void inorder(struct Db* root, int depth){
    if(root != NULL){
        inorder(root->right, depth + 1); // Visit right subtree first for better visualization
        for(int i = 0; i < depth; i++) {
            printf("   "); // Print indentation based on depth
        }
        printf("%d\n", root->phoneNumber); // Print the current node's data
        inorder(root->left, depth + 1); // Visit left subtree
    }
}

struct Db* searchUserByPhoneNumber(struct Db* root, int phoneNumber){
    if(root == NULL || phoneNumber == root->phoneNumber){
        printf("\nFound!\n");
        return root;
    }

    if(root->phoneNumber > phoneNumber){
        return searchUserByPhoneNumber(root->left, phoneNumber);
    }

    return searchUserByPhoneNumber(root->right, phoneNumber);
}

struct Db* findMin(struct Db* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

struct Db* deleteNode(struct Db* root, int phoneNumber){
    if(root == NULL){
        return root;
    }

    if(root->phoneNumber > phoneNumber)
        root->left = deleteNode(root->left, phoneNumber);
    else if (root->phoneNumber < phoneNumber)
        root->right = deleteNode(root->right, phoneNumber);
    else {
        if (root->right == NULL || root->left == NULL) {
            struct avlNode *temp = root->left ? root->left : root->right;
            free(root);
            return temp;
        } else {
            struct Db *temp = findMin(root->right);
            root->phoneNumber = temp->phoneNumber;
            root->right = deleteNode(root->right, temp->phoneNumber);
        }

        if (root == NULL)
            return root;
        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
        int balanceFactor = getBalanceFactor(root);

        // Left Left Case
        if(balanceFactor > 1 && phoneNumber < root->left->phoneNumber){
            return rightRotate(root);
        }
        // Right Right Case
        if(balanceFactor < -1 && phoneNumber > root->right->phoneNumber){
            return leftRotate(root);
        }
        // Left Right Case
        if(balanceFactor > 1 && phoneNumber > root->left->phoneNumber){
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        // Right Left Case
        if(balanceFactor < -1 && phoneNumber < root->right->phoneNumber){
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root; // Return the updated root
    }
}

#endif
