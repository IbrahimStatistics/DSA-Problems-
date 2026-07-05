class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        int charc[26];

        for(int i = 0; i<s.size(); i++) {
            charc[s[i] - 'a']++;
            charc[t[i] - 'a']--;
        }

        for(int i : charc)
            if(i != 0) return false;
            
        return true;
    }
};