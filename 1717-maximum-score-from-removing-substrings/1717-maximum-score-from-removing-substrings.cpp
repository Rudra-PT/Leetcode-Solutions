class Solution {
public:
    int maximumGain(string s, int x, int y) {

        string high_pair = (x > y) ? "ab" : "ba";
        string low_pair = (x > y) ? "ba" : "ab";
        int high_score = max(x, y);
        int low_score = min(x, y);
        
        int total_score = 0;
        
        string stack1 = "";
        for (char c : s) {
            if (!stack1.empty() && stack1.back() == high_pair[0] && c == high_pair[1]) {
                stack1.pop_back(); 
                total_score += high_score;
            } else {
                stack1.push_back(c);
            }
        }
        

        string stack2 = "";
        for (char c : stack1) {
            if (!stack2.empty() && stack2.back() == low_pair[0] && c == low_pair[1]) {
                stack2.pop_back(); 
                total_score += low_score;
            } else {
                stack2.push_back(c);
            }
        }
        
        return total_score;
    }
};