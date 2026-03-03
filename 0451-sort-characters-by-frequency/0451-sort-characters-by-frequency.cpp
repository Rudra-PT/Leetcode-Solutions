class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mpp;
        vector<pair<char, int>> vec;
        int n = s.length();
    
        for(int i = 0; i < n; i++){
            mpp[s[i]]++;
        }
        for(auto it : mpp){
            vec.push_back(it);
        }
        sort(vec.begin(), vec.end(), [](pair<char, int>& a, pair<char, int>& b) {
            return a.second > b.second; 
        });
        string result = "";
        for(auto it : vec) {
            result.append(it.second, it.first); 
        }

        return result;
    }
};