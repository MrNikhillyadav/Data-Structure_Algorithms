class Solution {
public:
    bool isSameTree(TreeNode* a, TreeNode* b) {
        if (a == NULL && b == NULL) return true;

        if (a == NULL || b == NULL) return false;

        if (a->val != b->val) return false;

        bool leftCheck = isSameTree(a->left, b->left);
        bool rightCheck = isSameTree(a->right, b->right);

        if (leftCheck && rightCheck) {
            return true;
        } else {
            return false;
        }
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL) {
            return false;
        }

        if (isSameTree(root, subRoot)) return true;

        bool leftAns = isSubtree(root->left, subRoot);
        bool rightAns = isSubtree(root->right, subRoot);

        if (leftAns == true || rightAns == true) { // subtree found either on left or right
            return true;
        }

        return false;
    }
};

/*  Mental Note:
        “At every node, try to match full subtree”

    Flow:
        for each node in root:
            if sameTree(root, subRoot):
                return true
            else:
                check left + right
*/