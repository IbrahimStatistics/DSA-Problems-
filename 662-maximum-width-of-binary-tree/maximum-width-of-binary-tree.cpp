class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int maxWidth = 0;

        while(!q.empty()) {
            int currLevelSize = q.size();
            int stIdx = q.front().second;
            int endIdx = q.back().second;

            maxWidth = max(maxWidth, endIdx - stIdx + 1);

            for(int i = 0; i < currLevelSize; i++) {
                auto curr = q.front();
                q.pop();

                // Normalize index to prevent overflow
                int normalizedIdx = curr.second - stIdx;
                
                if(curr.first->left) {
                    q.push({curr.first->left, (long long)normalizedIdx * 2 + 1});
                }

                if(curr.first->right) {
                    q.push({curr.first->right, (long long)normalizedIdx * 2 + 2});
                }
            }
        }

        return maxWidth;
    }
};