class Solution {
public:
    string f(int i, int isGreater, map<char, int> &mappa, string &curr, string &target){
        int n = target.size();
        if(i == n/2){
            if(n % 2){
                char lastOne;
                for(auto [c, freq]: mappa){
                    if(freq == 1){
                        lastOne = c;
                        break;
                    }
                }
                string poss = curr;
                poss.push_back(lastOne);
                for(int j = n / 2 - 1;j >= 0;j--)
                    poss.push_back(curr[j]);
                if(poss > target)
                    return poss;
                return "";
            }
            else{
                string poss = curr;
                for(int j = n / 2 - 1;j >= 0;j--)
                    poss.push_back(curr[j]);
                if(poss > target)
                    return poss;
                return "";
            }
        }
        string res;
        for(auto [c, freq]: mappa){
            if(freq <= 1)
                continue;
            if(!isGreater and c < target[i])
                continue;
            if(c > target[i]){
                mappa[c]-=2;
                curr.push_back(c);
                res = f(i+1, true, mappa, curr, target);
                break;
            }
            else{
                mappa[c] -= 2;
                curr.push_back(c);
                res = f(i+1, isGreater, mappa, curr, target);
                if(!res.empty())
                    return res;
                curr.pop_back();
                mappa[c] += 2;
            }
        }
        return res;
    }
    string lexPalindromicPermutation(string s, string target) {
        map<char, int> mappa;
        for(char c: s)
            mappa[c]++;
        string curr;
        string res = f(0, false, mappa, curr, target);
        return res;
    }
};