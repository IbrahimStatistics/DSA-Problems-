class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool isInc = true;
        for(int i = 0; i<nums.size()-1; i++) {
            if(nums[i]>nums[i+1])
                isInc = false;
        }

        bool isDec = true;
        for(int i = 0; i<nums.size()-1; i++) {
            if(nums[i]<nums[i+1])
                isDec = false;
        }

        return isInc || isDec;
    }
};