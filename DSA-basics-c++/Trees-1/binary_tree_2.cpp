#include <iostream>
using namespace std;

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

//building input based tree
TreeNode* buildTree(){
    int d;
    cin >> d;

    if(d == -1) return NULL;

    TreeNode* root = new TreeNode(d);
    root -> left = buildTree();
    root -> right = buildTree();
    
    return root;
}

//preorder
void printTree(TreeNode* root){
   if(root == NULL) return;

   cout << root -> data << " ";
   printTree(root->left);
   printTree(root->right);

}

int treeHeight(TreeNode* root){
    if(root == NULL) return 0;
    int lHeight = treeHeight(root-> left);
    int rHeight = treeHeight(root-> right);

    return 1 + max(lHeight,rHeight);
}

void printKthLevel(TreeNode* root, int k){
    if( root == NULL) return ;

    if(k == 1){
        cout << root-> data << " " ;
        return;
    }
    printKthLevel(root->left,k-1);
    printKthLevel(root->right,k-1);
    return;
}

void printAllLevels(TreeNode* root){
    if(root == NULL) return;
    int H = treeHeight(root);

    for(int i = 1; i <= H; i++){
        printKthLevel(root, i);
        cout << endl;
    }
    return;
}

int count(TreeNode* root){
    if(root == NULL) return 0;

    return 1 + count(root->left) + count(root->right);
}

int diameter(TreeNode* root){
    if(root == NULL) return 0;

    int h1 = treeHeight(root->left);
    int h2 = treeHeight(root->right);
    int op1 = h1 + h2;

    int op2 = diameter(root->left);
    int op3 = diameter(root->right);

    return max(op1,max(op2,op3));
}

int main(){
    TreeNode* root = buildTree();

    // e.g. Tree input : 3 4 -1 6 -1 -1 5 1 -1 -1 -1
    printTree(root);

    cout << endl;

    // tree height : Input = 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1 -1 
    cout << "tree height: " << treeHeight(root) << endl;

    // print Kth level e.g. k=3
    printKthLevel(root, 4);

    // print All levels
    printAllLevels(root);

    //total no. of nodes
    cout << "No. of nodes: " << count(root) << endl;


    //Diameter of tree
    cout<< "diameter: " << diameter(root);
    
    return 0;
}