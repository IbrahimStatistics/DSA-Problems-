class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size() == 0) return {{}};
        map<vector<int>, vector<string>> maps;

        for (int i = 0; i < strs.size(); i++) {
            vector<int> temp(26, 0);

            for (int j = 0; j < strs[i].size(); j++) {
                int idx = strs[i][j] - 'a';
                temp[idx]++;
            }

            maps[temp].push_back(strs[i]);
        }

        vector<vector<string>> ans;

        for (auto &p : maps) {
            ans.push_back(p.second);
        }

        return ans;
    }
};