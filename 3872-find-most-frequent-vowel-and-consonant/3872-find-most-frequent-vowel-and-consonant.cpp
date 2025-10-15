class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int>vowel;
        unordered_map<char , int> conso ;
        int maxV= 0 ;
        int maxC= 0 ;

        int n = s.length();
        for(int i = 0 ; i<n; i++){
            if(s[i]=='a'|| s[i]=='e'||s[i]=='i'||s[i]=='o'|| s[i]=='u' ){
                vowel[s[i]]++;
            } else{conso[s[i]]++;
            }
        } for(auto it :vowel){
            if(it.second>maxV){
                maxV= it.second;
            }
           }
           for(auto it : conso){
            if(it.second>maxC){
                maxC= it.second;
            }
           }
        return maxV+maxC;
    }
};