class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st = 0;
        int end = arr.size() - 1;

        while (st < end) {
            int mid = st + (end - st) / 2;

            if (arr[mid] < arr[mid + 1]) {
                // Increasing slope → peak is on the right
                st = mid + 1;
            } 
            else {
                // Decreasing slope → peak is at mid or on the left
                end = mid;
            }
        }

        return st;
    }
};