class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int, int> maps;
        int rows = grid.size();
        int cols = grid[0].size();
        int repeating, missing;

        for(int i = 0; i<rows; i++) {
            for(int j = 0; j<cols; j++) {
                if(maps.find(grid[i][j]) != maps.end()) {
                    repeating = grid[i][j];
                }

                maps[grid[i][j]] = 1;
            }
        }

        for(int i = 1; i<=rows*rows; i++) {
            if(maps.find(i) == maps.end()) {
                missing = i;
            }
        }
        
        vector<int> ans = {repeating, missing};
        return ans;
    }
};