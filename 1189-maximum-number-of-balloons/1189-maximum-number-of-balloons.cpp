class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.length();
        unordered_map<char ,int>count;
        for(int i = 0 ; i< n ; i++){
            count[text[i]]++;
        }
       return min({count['b'], count['a'], count['l'] / 2, count['o'] / 2, count['n']});
    }
};