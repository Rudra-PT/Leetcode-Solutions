class Solution {
public:
    int countSegments(string s) {
        vector<string>res;

        istringstream ss(s);
        string word;

        while(ss>>word){
            res.push_back(word);
        }
        return res.size();
    }
};