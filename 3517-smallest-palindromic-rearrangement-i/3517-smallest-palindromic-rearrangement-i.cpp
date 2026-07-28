class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        int mid = n/2;

        sort(s.begin(),s.begin()+mid);
        sort(s.end()-mid,s.end());
        reverse(s.end()-mid,s.end());
        return s;


    }
};