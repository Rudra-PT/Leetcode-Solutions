class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        int count = 0 ;
        unordered_map<char ,int> mpp;
        for(int i = 0 ; i < n ; i++){
            mpp[s[i]]++;
        }
        for(auto it : mpp){
            if(it.second < 3 ){
                count+=it.second;
            }
            else if(it.second % 2 ==0){
                 count+=2;
            }
            else{
                count+=1;
            }
        }
        return count;
    }
};