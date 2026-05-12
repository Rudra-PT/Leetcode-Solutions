class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> mpp;
        for (char c : s) {
            mpp[c]++;
        }

        vector<int> temp;
        for (auto it : mpp) {
            temp.push_back(it.second);
        }

        sort(temp.begin(), temp.end(), greater<int>());

        int count = 0;
        for (int i = 0; i < (int)temp.size() - 1; i++) {
            if (temp[i+1] >= temp[i]) {
                int prevAllowed = max(0, temp[i] - 1);
                count += (temp[i+1] - prevAllowed);
                temp[i+1] = prevAllowed;
            }
        }

        return count;
    }
};