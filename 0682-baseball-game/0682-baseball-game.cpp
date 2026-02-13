class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        stack<int> st;

        for(int i = 0 ; i < n  ; i ++){
            string s = operations[i];
            if(s == "+"){
                int a  = st.top(); st.pop();
                int b = st.top(); st.pop();

                int ans = a+b;
                st.push(b);
                st.push(a);
                st.push(ans);
            }
            else if(s == "D"){
                int x= st.top();
                int ans = x*2;
                st.push(ans);
            }
            else if(s=="C"){
                st.pop();
            }
            else{
                st.push(stoi(s));
            }
        }
        int res = 0;
        while( ! st.empty()){
            res += st.top();
            st.pop();
        }
        return res;
    }
};