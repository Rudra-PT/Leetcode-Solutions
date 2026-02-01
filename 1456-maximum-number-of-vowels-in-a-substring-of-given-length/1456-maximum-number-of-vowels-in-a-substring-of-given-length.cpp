class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        int currentVowels = 0;
        
        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) currentVowels++;
        }

        int maxV = currentVowels;
        for (int i = k; i < n; i++) {
            if (isVowel(s[i])) currentVowels++;
            if (isVowel(s[i - k])) currentVowels--;

            maxV = max(maxV, currentVowels);
            if (maxV == k) return k; 
        }

        return maxV;
    }
};