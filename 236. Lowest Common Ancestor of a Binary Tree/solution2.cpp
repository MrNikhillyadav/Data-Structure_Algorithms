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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left && right) return root;

        return left ? left : right;
    }
};

/*
    One-Line Memory Trick
        LCA = where left & right both return non-null

    Mental Model (Very Important)
        “Return the node if found, otherwise bubble up the answer”

    Quick Example
        p = 5, q = 4
        Flow:
            LCA(5) → returns 5
            LCA(4) → returns 4

            At node 5:
                left = NULL
                right = 4
                → return 5
            Final answer = 5

    Simple LCA Insight
        At every node, just think:
            - “Did I find p or q on my left side?”
            - “Did I find p or q on my right side?”

        Then decide:
            - If both left and right returned something
                “I found one node on each side → I am the LCA”
            - If only left returned something
                “Both nodes are somewhere on the left → go left”
            - If only right returned something
                “Both nodes are somewhere on the right → go right”
            - If both are null
                “Nothing found here”
*/