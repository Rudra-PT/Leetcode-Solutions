class Solution {
    private:
    int helper(int num){
        string s = to_string(num);
        if(s.length() <3 ) return 0;

        int waviness =0;
        for(int i=1; i<s.length()-1 ; i++){
            bool peak = (s[i] > s[i - 1] && s[i] > s[i + 1]);
            bool valley = (s[i] < s[i - 1] && s[i] < s[i + 1]);
            if (peak || valley) {
                waviness++;
            }
        }
        return waviness;
    }
public:
    int totalWaviness(int num1, int num2) {
        int totalSum = 0;
        for (int i = num1 ; i<= num2 ; i++){
            totalSum+=helper(i);
        }
        return totalSum;
    }
};