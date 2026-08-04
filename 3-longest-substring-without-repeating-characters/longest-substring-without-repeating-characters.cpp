class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastIndex;

        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.size(); right++) {

            // If character already exists in the current window,
            // move the left pointer
            if (lastIndex.find(s[right]) != lastIndex.end() &&
                lastIndex[s[right]] >= left) {
                left = lastIndex[s[right]] + 1;
            }

            // Update the last seen index of the current character
            lastIndex[s[right]] = right;

            // Update the maximum window size
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
