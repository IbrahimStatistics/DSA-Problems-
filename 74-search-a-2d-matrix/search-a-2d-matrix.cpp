class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Binary search for the candidate row
        int top = 0;
        int bottom = rows - 1;

        while (top <= bottom) {
            int mid = top + (bottom - top) / 2;

            if (matrix[mid][0] <= target) {
                top = mid + 1;
            } else {
                bottom = mid - 1;
            }
        }

        // No row can contain target
        if (bottom < 0)
            return false;

        int target_row = bottom;

        // Binary search within the row
        int left = 0;
        int right = cols - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (matrix[target_row][mid] == target)
                return true;
            else if (matrix[target_row][mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return false;
    }
};