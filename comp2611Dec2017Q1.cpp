#include <iostream>

struct BSTNode {
    int key;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int k) : key(k), left(nullptr), right(nullptr) {}
};

BSTNode* searchElseInsert(BSTNode* root, int key) {
    if (root == nullptr) {
        return new BSTNode(key); // would use createNode() here but i cant be bothered writing it, assume its createNode()
    }
    if (key == root->key) {
        std::cout << "Key " << key << " already exists in the tree.\n"; // Whats a namespace?
        return root;
    }
    if (key < root->key) {
        root->left = searchElseInsert(root->left, key);
    } else {
        root->right = searchElseInsert(root->right, key);
    }
    return root;
}

void inorderTraversal(BSTNode* root) {
    //Won't have to write this in the exam, but for testing purposes included
    if (root != nullptr) {
        inorderTraversal(root->left);
        std::cout << root->key << " ";
        inorderTraversal(root->right);
    }
}

void deleteLargest(BSTNode * root){
    BSTNode * previousNode = root;
    BSTNode * temp = root;

    while (temp -> right != NULL){
        previousNode = temp;
        temp = temp -> right;
    }

    if (temp->left != nullptr) {
        previousNode->right = temp->left;
    }


    if (temp->left == nullptr) {
        previousNode->right = nullptr;
    }
}

int main() {
    BSTNode* root = nullptr;
    root = searchElseInsert(root, 10);
    root = searchElseInsert(root, 5);
    root = searchElseInsert(root, 20);
    root = searchElseInsert(root, 10); 
    root = searchElseInsert(root, 50); 

    std::cout << "Inorder traversal of the BST: ";
    inorderTraversal(root);
    std::cout << std::endl;
    deleteLargest(root);
    inorderTraversal(root);
    // memory dosent grow on trees (even binary) we free everything
    delete root->left; 
    delete root->right;
    delete root;
    return 0;
}