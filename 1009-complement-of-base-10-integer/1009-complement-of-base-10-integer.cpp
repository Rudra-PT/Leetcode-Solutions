class Solution {
public:
    int bitwiseComplement(int n) {
        string s = format("{:b}" , n);
        int size = s.length();
        string ans;
        for(int i = 0 ; i< size ; i++){
            if(s[i]=='0') ans+='1';
            else{
                ans+='0';
            }
    }
     int decimal_value = std::stoi(ans, nullptr, 2);
        return decimal_value;
}
};