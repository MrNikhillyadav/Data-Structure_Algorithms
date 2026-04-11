/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans = NULL;

    int LCA(TreeNode* &root, TreeNode* &p, TreeNode* &q){
        if(root == NULL) return NULL;

        int leftRes = LCA(root->left, p,q);
        int rightRes = LCA(root->right, p,q);

        int self = 0;

        if(root == p || root == q){
            self = 1;
        }

        int total = self + leftRes + rightRes;

        if(total >= 2 && ans == NULL){ // taaki first 2 jaise hi ho to uss node ko ans me daaldein (least Common).
            ans = root;
        }

        return total;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       LCA(root, p, q);
       return ans;
    }
};
//Intuition Video : Padho with pratyush

/* 
    Pattern
        “Return info upward + capture answer globally”

    Why ans must be global/reference?
        Because:  Child finds LCA → parent should not overwrite it
*/