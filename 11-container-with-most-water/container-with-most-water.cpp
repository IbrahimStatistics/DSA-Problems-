class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_vol = INT_MIN;

        int start = 0;
        int end = height.size()-1;

        while(start<end) {
            int container_height = min(height[start], height[end]);
            int width = end - start;

            int curr_vol = container_height * width;

            max_vol = max(max_vol, curr_vol);

            if(height[start] < height[end]) start++;
            else end--;
        }

        return max_vol;
    }
};