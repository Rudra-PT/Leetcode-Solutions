class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
       
        for (char ch : s) {
            if (ch != ']') {
                st.push(ch);
            } else {
                string temp = "";
                while (!st.empty() && st.top() != '[') {
                    temp.push_back(st.top());
                    st.pop();
                }
                reverse(temp.begin(), temp.end());
                st.pop();


                string num = "";
                while (!st.empty() && isdigit(st.top())) {
                    num.push_back(st.top());
                    st.pop();
                }
                reverse(num.begin(), num.end());
                int k = stoi(num);

        
                string expanded = "";
                for (int i = 0; i < k; i++) {
                    expanded += temp;
                }
                for (char c : expanded) {
                    st.push(c);
                }
            }
        }
        string ans = "";
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};