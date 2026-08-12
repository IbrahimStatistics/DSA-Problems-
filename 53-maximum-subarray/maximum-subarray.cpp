class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        bool allNegative = true;
        for(int i = 0; i<nums.size(); i++) {
            if(nums[i]>0) allNegative = false;
        }

        if(allNegative) {
            sort(nums.begin(), nums.end());
            return nums[nums.size()-1];
        }

        int sum = 0;
        int currSum = 0;
        
        for(int i = 0; i<nums.size(); i++) {
            currSum+=nums[i];
            if(currSum < 0) currSum = 0;
            sum = max(sum, currSum);
        }

        return sum;
    }
};