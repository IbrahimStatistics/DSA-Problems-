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
    bool isSame(TreeNode* left, TreeNode* right) {
        if(left == NULL && right == NULL) return true;
        if(left == NULL || right == NULL) return false;

        bool isLeftSame = isSame(left->left, right->right);
        bool isRightSame = isSame(left->right, right->left);

        return isLeftSame && isRightSame && left->val == right->val;
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;

        return isSame(root->left, root->right);
    }
};