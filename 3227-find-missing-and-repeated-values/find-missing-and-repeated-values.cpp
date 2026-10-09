class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<int> arr(rows*cols+1, 0);

        for(int i = 0; i<rows; i++) {
            for(int j = 0; j<cols; j++) {
                arr[grid[i][j]] ++;
            }
        }

        int missing, repeating;

        for(int i = 0; i<arr.size(); i++) {
            if(arr[i] == 0)
                missing = i;
            if(arr[i] == 2)
                repeating = i;
        }

        return {repeating, missing};
    }
};