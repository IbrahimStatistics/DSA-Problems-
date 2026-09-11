class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        queue<int> q;                      // store indices

        for (int i = 0; i < (int)s.size(); i++) {
            if (m.find(s[i]) == m.end()) {
                q.push(i);                 // push index, not char
            }
            m[s[i]]++;
        }

        while (!q.empty() && m[s[q.front()]] > 1) {
            q.pop();
        }

        return q.empty() ? -1 : q.front(); // return index, or -1 if none
    }
};