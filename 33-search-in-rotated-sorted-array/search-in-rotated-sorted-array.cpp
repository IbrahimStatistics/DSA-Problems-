class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 1) {
            if(nums[0] == target) return 0;
            else return -1;
        }

        int k;
        for(int i = 0; i<nums.size()-1; i++) {
            if(nums[i] < nums[i+1]) continue;
            else k = i;     
        }

        int n = nums.size();
        int start;
        int end;

        if(nums[0] <= target && target <=nums[k]) {
            start = 0;
            end = k;
        } else if(nums[k+1]<=target && target <= nums[n-1]) {
            start = k+1;
            end = n-1;
        }

        while(start<=end) {
            int mid = start+(end-start)/2;

            if(target == nums[mid]) return mid;
            else if(target>nums[mid]) start = mid + 1;
            else if(target<nums[mid]) end = mid - 1;

        }

        return -1;
    }
};