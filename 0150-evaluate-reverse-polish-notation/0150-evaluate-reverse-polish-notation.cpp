class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st; 
        
        int n = tokens.size();
        for(int i=0; i<n; i++){
            string token = tokens[i];
            
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                
                if(token == "+") st.push(a+b);
                else if(token == "-") st.push(a-b);
                else if(token == "*") st.push(a*b);
                else if(token == "/") st.push(a/b);
            }
            else{
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};