class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(char c : num){
            while(!st.empty() && k > 0 && st.top() > c){
                st.pop();
                k--;
            }
            st.push(c);
        }
        while(k > 0 && !st.empty()){
            st.pop();
            k--;
        }
        string result = "";
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        int i = 0;
        while(i < result.length() && result[i] == '0'){
            i++;
        }
        result = result.substr(i);
        return result == "" ? "0" : result;
    }
};