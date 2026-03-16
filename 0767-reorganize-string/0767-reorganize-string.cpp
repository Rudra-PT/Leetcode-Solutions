class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char , int>mpp;
        priority_queue<pair<int, char>> pq;
        int n = s.length();
        for(int i = 0 ; i < n ; i++){
            mpp[s[i]]++;
        }
        string ans = "";
        for(auto it : mpp){
            if(it.second > (n+1)/2){
                return ans;
            }
            pq.push({it.second , it.first});
        }
        pair temp = {-1 , '#'};
        while(!pq.empty()){
            pair curr = {pq.top().first , pq.top().second};
            pq.pop();
            ans+=curr.second ;
            curr.first --;
            if(temp.first >0){
                pq.push(temp);
            }
            temp = curr;
        
        }
return ans;

    }
};