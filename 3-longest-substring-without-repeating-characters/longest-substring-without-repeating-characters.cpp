class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int ans = 0;
        
        unordered_set<char> charSet;

        for(int right = 0; right < s.length(); right++) {
            while(charSet.find(s[right]) !=charSet.end()) {
                charSet.erase(s[left]);
                left++;
            }

            charSet.insert(s[right]);
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};