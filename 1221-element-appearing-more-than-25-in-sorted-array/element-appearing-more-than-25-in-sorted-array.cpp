class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int, int> maps;
        float freq = 0.25 * arr.size();

        for(int i = 0; i<arr.size(); i++) {
            if(maps.find(arr[i])!=maps.end()) maps[arr[i]]++;
            else maps[arr[i]] = 1;
        }

        for(const auto& i : maps) {
            if (i.second > freq) return i.first;
        }
        
        return arr[0];
    }
};