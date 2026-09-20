class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();

        if(n == 1) return true;

        vector<unordered_set<int>> dp(n);

        dp[0].insert(0);
        if(stones[1] != 1) return false;
        dp[1].insert(1);

        unordered_map<int,int> pos;
        for(int i = 0; i < n; i++) pos[stones[i]] = i;

        for(int i = 1; i < n; i++) {
            for(int k : dp[i]) {
                for(int jump = k - 1; jump <= k + 1; jump++) {
                    if(jump <= 0) continue;
                    int next = stones[i] + jump;
                    if(pos.count(next)) {
                        dp[pos[next]].insert(jump);
                    }
                }
            }
        }

        return !dp[n-1].empty();
    }
};