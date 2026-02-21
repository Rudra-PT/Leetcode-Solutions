class Solution {
public:
    bool helper(int num){
        string s = format("{: b}" , num);
        cout<<s;
        int oneCount = 0 ;
        for(int i = 0; i< s.length() ;i++){
            if(s[i] == '1') oneCount++;
        }
        if(oneCount == 2 || oneCount == 3 || oneCount == 5 || oneCount == 7 || oneCount == 11 || oneCount == 13 || oneCount == 17 || oneCount == 19 ){
            return true;
        }
        return false ;
        
    }



    int countPrimeSetBits(int left, int right) {
        int ansCount = 0 ;
        for (int i = left ; i <= right; i++){
           if(helper(i)) ansCount++;
        }
        return ansCount;
    }
};