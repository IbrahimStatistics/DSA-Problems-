/**
 * Definition for a binary tree TreeNode.
 * struct TreeTreeNode {
 *     int val;
 *     TreeTreeNode *left;
 *     TreeTreeNode *right;
 *     TreeTreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeTreeNode(int x, TreeTreeNode *left, TreeTreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void allPaths(TreeNode* root, string path, vector<string>& ans) {

        if(root == NULL)
            return;

        // Leaf TreeNode
        if(root->left == NULL && root->right == NULL) {
            ans.push_back(path);
            return;
        }

        if(root->left) {
            allPaths(
                root->left,
                path + "->" + to_string(root->left->val),
                ans
            );
        }

        if(root->right) {
            allPaths(
                root->right,
                path + "->" + to_string(root->right->val),
                ans
            );
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;

        if(root == NULL)
            return ans;

        string path = to_string(root->val);

        allPaths(root, path, ans);

        return ans;
    }
};