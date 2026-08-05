class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> missing = {};

        for(int i = 1; i<nums.size(); i++) {
            int missingNum = 0;
            if(nums[i] == nums[i-1] + 1) continue;
            else {
                int j = 1;
                while(missingNum != nums[i]) {
                    missingNum = nums[i-1] + j++;
                    if(missingNum == nums[i]) break;
                    missing.push_back(missingNum);
                }
            }
        }
            
        return missing;
    }
};