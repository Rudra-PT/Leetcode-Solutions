class Solution {
private: 
    static int numberofOne(int n){
        int c = 0;
        while( n > 0){
            if(n & 1) c++;
            n = n >> 1;
        }
        return c;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> pairs;
        for(int i = 0; i < arr.size(); i++){
            int oneCount = numberofOne(arr[i]);
            pairs.push_back({oneCount, arr[i]});
        }
        sort(pairs.begin(), pairs.end());
        for(int i = 0; i < pairs.size(); i++){
            arr[i] = pairs[i].second;
        }
        return arr;
    }
};