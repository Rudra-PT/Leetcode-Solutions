class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0, right = 0;
        unordered_map<char, int> count; 
        int ans = 0;
        int n = s.length();

        for(right = 0; right < n; right++) {
            count[s[right]]++;

            while(count.size() == 3) {
                ans += (n - right);
                
                char leftChar = s[left];
                count[leftChar]--;
                if(count[leftChar] == 0) {
                    count.erase(leftChar); 
                }
                left++;
            }
        }
        return ans;
    }
};