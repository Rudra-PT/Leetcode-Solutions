class Solution {
private:
    long long nCk(int n, int k, long long maxK) {
        if (k < 0 || k > n) return 0;
        if (k == 0 || k == n) return 1;
        if (k > n - k) k = n - k;
        
        long long res = 1;
        for (int i = 1; i <= k; i++) {
            res = res * (n - i + 1) / i;
            if (res > maxK) return maxK + 1;
        }
        return res;
    }
    long long countArrangements(vector<int>& halfFreq, long long maxK) {
        int total = 0;
        for (int f : halfFreq) total += f;

        long long res = 1;
        for (int f : halfFreq) {
            if (f > 0) {
                res *= nCk(total, f, maxK);
                if (res > maxK) return maxK + 1;
                total -= f;
            }
        }
        return res;
    }

public:
    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        int oddCount = 0;
        char middleChar = '\0';
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) {
                oddCount++;
                middleChar = i + 'a';
            }
        }

        if (oddCount > 1) {
            return "";
        }
        vector<int> halfFreq(26, 0);
        int halfLen = 0;
        for (int i = 0; i < 26; i++) {
            halfFreq[i] = freq[i] / 2;
            halfLen += halfFreq[i];
        }
        long long totalPerms = countArrangements(halfFreq, k);
        if (totalPerms < k) {
            return "";
        }

        string halfString = "";
        long long currentK = k;

        for (int step = 0; step < halfLen; step++) {
            for (int i = 0; i < 26; i++) {
                if (halfFreq[i] > 0) {
                    halfFreq[i]--;
                    long long arrangements = countArrangements(halfFreq, currentK);
                    
                    if (arrangements >= currentK) {
                        halfString += (char)(i + 'a');
                        break; 
                    } else {
                        currentK -= arrangements;
                        halfFreq[i]++;
                    }
                }
            }
        }
        string result = halfString;
        if (middleChar != '\0') {
            result += middleChar;
        }
        string rightHalf = halfString;
        reverse(rightHalf.begin(), rightHalf.end());
        result += rightHalf;

        return result;
    }
};