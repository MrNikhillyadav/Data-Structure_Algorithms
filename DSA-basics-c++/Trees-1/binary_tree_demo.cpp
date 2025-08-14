/*
 * Title: Binary Tree Implementation & Traversals Demo
 * Description: C++ code for binary tree, including node definition,
 *              creation, traversals (preorder, inorder, postorder, level order),
 *              height calculation, and mirror function.
 * Author: Nikhil Yadav .
 * Date: August 2025
 */

#include <iostream>
#include <queue>
using namespace std;

// Tree node definition
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) {
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL; 
    }
};


// ============ TREE BUILDERS ===============

TreeNode* buildSampleTree() {
    //    1
    //   / \
    //  2   3
    // / \   \
    //4  5    6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    return root;
}

// ============ TRAVERSALS ===============

// Preorder: Root Left Right
void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Inorder: Left Root Right
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Postorder: Left Right Root
void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

//print kth level of tree
void printKthLevel(TreeNode* root, int k){
    if(!root) return;
    if(k == 1) {
        cout << root -> data << " " ;
        return;
    }
    printKthLevel(root->left, k-1);
    printKthLevel(root->right, k-1);
    return;
}

// Print all levels
void printAllLevels(TreeNode* root){
    int H = treeHeight(root);

    for(int i=1; i<= H; i++){
        printKthLevel(root, i);
        cout << endl;
    }
    return;
}

// ============ UTILITY FUNCTIONS ===============

// Height of the tree (number of nodes in longest path from root to leaf)
int treeHeight(TreeNode* root) {
    if (!root) return 0;

    int lHeight = treeHeight(root->left);
    int rHeight = treeHeight(root->right);

    return max(lHeight, rHeight) + 1;
}

// Convert tree to its mirror
void mirrorTree(TreeNode* root) {
    if (!root) return;
    // Swap left and right
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    // Recurse for children
    mirrorTree(root->left);
    mirrorTree(root->right);
}

// Print tree (inorder for demonstration)
void printTree(TreeNode* root) {
    if (!root) return;
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}


// Free memory (recursive delete)
void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    TreeNode* root = buildSampleTree();

    cout << "Preorder Traversal: ";
    preorder(root); cout << endl;

    cout << "Inorder Traversal: ";
    inorder(root); cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root); cout << endl;

    cout << "Kth Level Traversal: ";
    printKthLevel(root,2);
    cout << endl;

    cout << "All levels: " << endl;
    printAllLevels(root);

    cout << endl;

    cout << "Height of tree: " << treeHeight(root) << endl;

    cout << "Mirroring the tree..." << endl;
    mirrorTree(root);

    cout << "Inorder Traversal after Mirror: ";
    inorder(root); cout << endl;

    // Free memory
    deleteTree(root);

    return 0;
}


/*
 * =========================
 *        EXPLANATION
 * =========================
 * TreeNode: Class for tree node (data, left, right)
 * BuildSampleTree: Manually creates a sample binary tree
 * preorder/inorder/postorder: Standard DFS traversals
 * printKthLevel : Prints all elements at level k
 * treeHeight: Recursive max-depth calculation
 * mirrorTree: Swaps left/right child at every node
 * printTree: Prints inorder traversal (used for demo)
 * deleteTree: Frees all allocated nodes
 *
 * Try changing the sample tree, or writing your own input code to make and test different trees!
 */
