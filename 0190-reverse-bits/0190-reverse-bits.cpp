class Solution {
public:
    int reverseBits(int n) {
        string s = bitset<32>(n).to_string();
        reverse(s.begin() , s.end());
        int ans = bitset<32>(s).to_ulong();

        return ans;

    }
};