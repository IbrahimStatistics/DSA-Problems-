class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> maps;

        for (int i = 0; i < nums.size(); i++) {
            int second = target - nums[i];

            if (maps.find(second) != maps.end()) {
                return {maps[second], i};
            }

            maps[nums[i]] = i;
        }

        return {-1, -1};
    }
};