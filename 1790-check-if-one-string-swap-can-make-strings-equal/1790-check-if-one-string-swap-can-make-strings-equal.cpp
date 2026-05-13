class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true;

        int n = s1.length();
        vector<int> diffs;

        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                diffs.push_back(i);
            }
        }
        if (diffs.size() == 2) {
            int i = diffs[0];
            int j = diffs[1];
            return (s1[i] == s2[j] && s1[j] == s2[i]);
        }
        return false;
    }
};