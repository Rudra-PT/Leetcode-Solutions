class Solution {
public:

    bool canFinish(vector<int>& piles, int h, int speed){
        long long time=0;
        for(int x : piles){
            time+=ceil(double(x)/speed);
        }
        return time<=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=*max_element(piles.begin(),piles.end());
        int ans=right;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(canFinish(piles,h,mid)){
                ans=mid;
                right=mid-1;
            }
            else left=mid+1; 
        }
        return ans;

    }
};