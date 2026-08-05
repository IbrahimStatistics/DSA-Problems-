class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();

        if(nums.capacity() > 0) {
            nums.reserve(nums.capacity() * 2);
        } else {
            nums.reserve(1);
        }

        for(int i = 0; i<n; i++) {
            nums.push_back(nums[i]);
        }

        return nums;
    }
};