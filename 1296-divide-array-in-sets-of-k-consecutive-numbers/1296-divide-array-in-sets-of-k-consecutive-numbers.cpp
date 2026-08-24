class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) {
            return false;
        }
        sort(hand.begin(), hand.end());
        for (int i = 0; i < n; i++) {
            if (hand[i] == -1) {
                continue;
            }
            int left = i + 1;
            int cur = hand[i] + 1;
            int found = 1;
            while (left < n && found != groupSize) {
                if (hand[left] > cur) {
                    return false;
                }
                if (hand[left] == cur) {
                    cur++;
                    found++;
                    hand[left] = -1;
                }
                left++;
            }
            if (found != groupSize) {
                return false;
            }
        }
        return true;
    }
};