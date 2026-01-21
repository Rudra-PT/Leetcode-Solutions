class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> charCounts(26, 0);
        for (char c : chars) {
            charCounts[c - 'a']++;
        }
        
        int ans = 0;

        for (string& word : words) {
            vector<int> wordCounts(26, 0);
            bool canForm = true;
        
            for (char c : word) {
                wordCounts[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                if (wordCounts[i] > charCounts[i]) {
                    canForm = false;
                    break;
                }
            }
            if (canForm) {
                ans += word.length();
            }
        }
        
        return ans;
    }
};