class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        ans.push_back(words[0]);  
        
        for (int i = 1; i < words.size(); i++) {
            string prev = ans.back();
            string cur = words[i];
            sort(prev.begin(), prev.end());
            sort(cur.begin(), cur.end());
            
            if (prev != cur) ans.push_back(words[i]); 
        }
        return ans;
    }
};
