class Solution {
public:
    int countSeniors(vector<string>& details) 
    {
        int n=details.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=11;j<13;j++)
            {
                sum=sum*10+(details[i][j]-'0');
            }
            if(sum>60) cnt++;
        }
        return cnt;
    }

};