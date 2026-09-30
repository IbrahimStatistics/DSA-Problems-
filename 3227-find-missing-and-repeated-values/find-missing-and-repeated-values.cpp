class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> count (n*n + 1, 0);

        int missing, repeated;

        for(auto& row : grid) {
            for(int v : row) {
                count[v]++;
            }
        }

        for(int i = 1; i<=n*n; i++) {
            if(count[i] == 0) missing = i;
            else if(count[i] == 2) repeated = i;
        }

        return {repeated,missing};
    }
};