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
    vector<int> inorder;
    void calculateInorder(TreeNode* root) {
        if(root == NULL) return;

        calculateInorder(root->left);
        inorder.push_back(root->val);
        calculateInorder(root->right);
    }

    int minDiffInBST(TreeNode* root) {
        int minDistance = INT_MAX;
        calculateInorder(root);

        for(int i = 1; i<inorder.size(); i++) {
            minDistance = min(minDistance, inorder[i]-inorder[i-1]);
        }

        return minDistance;
    }
};