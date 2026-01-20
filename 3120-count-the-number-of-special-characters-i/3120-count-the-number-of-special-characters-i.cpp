class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char , int> mpp;
        int count = 0 ; 
        for(int i = 0 ; i < word.length(); i++){
            mpp[word[i]]++;
        }
        for(auto letter : mpp){
            char ch = letter.first;
            if(islower(ch) && mpp.count(toupper(ch))) {
                count++;
        }
        
    }
    return count;
    }
};