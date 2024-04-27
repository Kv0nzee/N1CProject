#include <stdio.h>
#include <stdlib.h>


struct avlNode {
    int key;
    struct avlNode* left;
    struct avlNode* right;
    int height;
};

void inorder(struct avlNode* root, int depth);
int getHeight(struct avlNode* node);
struct avlNode* create(int key);
int max(int l, int r);
int getBalanceFactor(struct avlNode* node);
struct avlNode* leftRotate(struct avlNode* node);
struct avlNode* rightRotate(struct avlNode* node);
struct avlNode* insertNode(struct avlNode* root, int key);
void inorder(struct avlNode* root, int depth);
struct avlNode* findData(struct avlNode* root, int data);
struct avlNode* findMin(struct avlNode* root);
struct avlNode* deleteNode(struct avlNode* root, int key);

int getHeight(struct avlNode* node){
    if(node == NULL){
        return 0;
    }
    return  node->height;
}

struct avlNode* create(int key){
    struct avlNode* node = (struct avlNode*) malloc(sizeof (struct avlNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int max(int l, int r){
    return (l>r) ? l : r;
}

int getBalanceFactor(struct avlNode* node){
    if(node == NULL){
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

struct avlNode* leftRotate(struct avlNode* node){
    printf("Performing Left Rotation...\n");
    printf("Before Rotation:\n");
    inorder(node, 0);

    struct avlNode* x = node->right;
    struct avlNode* t2 = x->left;

    x->left = node;
    node->right = t2;

    node->height = max(getHeight(node->right), getHeight(node->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    printf("After Rotation:\n");
    inorder(x, 0);
    return x;
}

struct avlNode* rightRotate(struct avlNode* node){
    printf("Performing Right Rotation...\n");
    printf("Before Rotation:\n");
    inorder(node, 0);

    struct avlNode* x = node->left;
    struct avlNode* t2 = x->right;

    x->right = node;
    node->left = t2;

    node->height = max(getHeight(node->right), getHeight(node->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    printf("After Rotation:\n");
    inorder(x, 0);
    return x;
}

struct avlNode* insertNode(struct avlNode* root, int key){
    if(root == NULL)
        return create(key);

    if(root->key > key)
        root->left = insertNode(root->left, key);
    else if (root->key < key)
        root->right = insertNode(root->right, key);
    else
        return root;

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    int balanceFactor = getBalanceFactor(root);

    // Left Left Case
    if(balanceFactor > 1 && key < root->left->key){
        return rightRotate(root);
    }
    // Right Right Case
    if(balanceFactor < -1 && key > root->right->key){
        return leftRotate(root);
    }
    // Left Right Case
    if(balanceFactor > 1 && key > root->left->key){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // Right Left Case
    if(balanceFactor < -1 && key < root->right->key){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root; // Return the updated root
}

void inorder(struct avlNode* root, int depth){
    if(root != NULL){
        inorder(root->right, depth + 1); // Visit right subtree first for better visualization
        for(int i = 0; i < depth; i++) {
            printf("   "); // Print indentation based on depth
        }
        printf("%d\n", root->key); // Print the current node's data
        inorder(root->left, depth + 1); // Visit left subtree
    }
}

struct avlNode* findData(struct avlNode* root, int data){
    if(root == NULL || data == root->key){
        return root;
    }

    if(root->key > data){
        return findData(root->left, data);
    }

    return findData(root->right, data);
}

struct avlNode* findMin(struct avlNode* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

struct avlNode* deleteNode(struct avlNode* root, int key){
    if(root == NULL){
        return root;
    }

    if(root->key > key)
        root->left = deleteNode(root->left, key);
    else if (root->key < key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->right == NULL || root->left == NULL) {
            struct avlNode *temp = root->left ? root->left : root->right;
            free(root);
            return temp;
        } else {
            struct avlNode *temp = findMin(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }

        if (root == NULL)
            return root;
        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
        int balanceFactor = getBalanceFactor(root);

        // Left Left Case
        if(balanceFactor > 1 && key < root->left->key){
            return rightRotate(root);
        }
        // Right Right Case
        if(balanceFactor < -1 && key > root->right->key){
            return leftRotate(root);
        }
        // Left Right Case
        if(balanceFactor > 1 && key > root->left->key){
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        // Right Left Case
        if(balanceFactor < -1 && key < root->right->key){
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root; // Return the updated root
    }
}

int main() {
    struct avlNode* root = NULL;

    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(findData(root, 5), 15);
    root = insertNode(root, 20);
    root = insertNode(findData(root, 15), 3);
    root = insertNode(root, 8);
    root = insertNode(root, 13);
    inorder(root, 0);
    printf("Deleting Value in the tree!\n");
    deleteNode(root, 5);
    inorder(root, 0);

    struct avlNode* result = findData(root, 13);
    if (result != NULL) {
        printf("Value found in the tree!\n");
    } else {
        printf("Value not found in the tree.\n");
    }

    return 0;
}