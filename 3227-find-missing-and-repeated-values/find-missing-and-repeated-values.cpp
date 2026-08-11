class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int repeating = -1;
        int missing = -1;

        unordered_map<int, int> maps;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int val = grid[i][j];

                if (maps.find(val) != maps.end()) {
                    repeating = val;
                } else {
                    maps[val] = 1;
                }
            }
        }

        for (int num = 1; num <= rows * cols; num++) {
            if (maps.find(num) == maps.end()) {
                missing = num;
                break;
            }
        }

        return {repeating, missing};
    }
};