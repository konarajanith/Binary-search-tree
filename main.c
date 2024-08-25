#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a new node with given key
struct Node* insert(struct Node* node, int key) {
    // If the tree is empty, return a new node
    if (node == NULL) return newNode(key);

    // Otherwise, recur down the tree
    if (key < node->data) {
        node->left = insert(node->left, key);
    } else if (key > node->data) {
        node->right = insert(node->right, key);
    }

    // Return the (unchanged) node pointer
    return node;
}

// Function to search a given key in BST
struct Node* search(struct Node* root, int key) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key) {
        return root;
    }

    // Key is greater than root's key
    if (root->data < key) {
        return search(root->right, key);
    }

    // Key is smaller than root's key
    return search(root->left, key);
}

// Function to do in-order traversal of BST
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Main function to test the BST
int main() {
    struct Node* root = NULL;

    // Insert nodes into the BST
    int values[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    int n = sizeof(values) / sizeof(values[0]);
    int i;

    for ( i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    // Print the in-order traversal of the BST
    printf("In-order traversal of the BST:\n");
    inorder(root);

    // Search for a given node
    int keyToFind = 7;
    struct Node* result = search(root, keyToFind);
    if (result != NULL) {
        printf("\nNode %d is present in the BST.\n", keyToFind);
    } else {
        printf("\nNode %d is not present in the BST.\n", keyToFind);
    }

    return 0;
}

