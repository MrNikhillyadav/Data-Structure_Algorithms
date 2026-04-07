/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void levelOrderTraversal(TreeNode* root, vector<vector<int>>& res){
        if(root == NULL) return ;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();  // no. of nodes at this level
            vector<int> level;

            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                
                level.push_back(node->val);

                // BFS expansion
                if(node->left) {
                    q.push(node->left);
                }

                if(node->right) {
                    q.push(node->right);
                }
            }
            res.push_back(level);
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        levelOrderTraversal(root,res);

        return res;
    }
};

/*
    In level order (BFS):
        - You NEVER call recursion in BFS.
        - You ONLY use the Queue to move forward.

    Think Like This
      Queue always stores:
         “Nodes of NEXT level waiting to be processed”
*/