class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int st = 0;
        int end = nums.size() - 1;

        while (st < end) {
            int mid = st + (end - st) / 2;

            // Checks if mid is odd, and if so, shifts it back to start at an even index (the first element of a potential pair).
            if (mid % 2 == 1) {
                mid--;
            }

            // Checks if the current element matches its right neighbor (meaning the pair is complete and the single element lies to the right).
            if (nums[mid] == nums[mid + 1]) {
                st = mid + 2;
            } 
            // Triggers when the current element does not match its right neighbor (meaning the pair sequence is broken, so the single element is at mid or to the left).
            else {
                end = mid;
            }
        }

        return nums[st];
    }
};