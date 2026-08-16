class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0;
        int j = 0;
        int currLen = 0;
        int ans = 0;
        int maxFreq = 0;

        vector<int> freq(26, 0);

        while (j < s.size()) {
            freq[s[j] - 'A']++;

            maxFreq = max(maxFreq, freq[s[j] - 'A']);

            currLen = j - i + 1;

            if (currLen - maxFreq > k) {
                freq[s[i] - 'A']--;
                i++;
            }

            currLen = j - i + 1;
            ans = max(ans, currLen);

            j++;
        }

        return ans;
    }
};