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
    void zigzagTraversal(TreeNode* &root, vector<vector<int>>& res){
        if(root == NULL) return;

        queue<TreeNode*> q;
        q.push(root);

        bool flag = false;

        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            stack<int> reverseStack;

            for(int i=0; i< size; i++){
                TreeNode* Node = q.front();
                q.pop();

                if(flag){
                    reverseStack.push(Node->val);
                }else{
                    level.push_back(Node->val);
                }

                if(Node->left) q.push(Node->left);
                if(Node->right) q.push(Node->right);
            }

            while( !reverseStack.empty()){
                level.push_back(reverseStack.top());
                reverseStack.pop();
            }

            res.push_back(level);
            flag = !flag;
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        zigzagTraversal(root,res);

        return res;
    }
};

/* Approach 1: Queue + Stack  (BFS + reverse direction) :

    Using a stack works, but:
       - Extra space
       - Extra loop
        👉 Better approach: index trick (O(1))

    One-Line Memory Trick
        Zigzag = BFS + reverse indexing
    
*/