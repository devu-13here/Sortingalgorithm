#include <iostream>
using namespace std;

// Node structure
struct Node {
    int key;
    Node *left, *right;
};

// Utility function to create a new BST node
Node* newNode(int item) {
    Node* temp = new Node;
    temp->key = item;
    temp->left = temp->right = nullptr;
    return temp;
}

// Store in-order traversal of the BST
void storeSorted(Node* root, int arr[], int &i) {
    if (root != nullptr) {
        storeSorted(root->left, arr, i);
        arr[i++] = root->key;
        storeSorted(root->right, arr, i);
    }
}

// Insert a new node with given key in BST
Node* insert(Node* node, int key) {
    if (node == nullptr) return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

// Function to sort array using Tree Sort
void treeSort(int arr[], int n) {
    Node *root = nullptr;

    // Construct the BST
    root = insert(root, arr[0]);
    for (int i = 1; i < n; i++)
        insert(root, arr[i]);

    // Store in-order traversal of the BST
    int i = 0;
    storeSorted(root, arr, i);
}

// Driver Program to test above functions
int main() {
    int arr[] = {5, 4, 7, 2, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    treeSort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
