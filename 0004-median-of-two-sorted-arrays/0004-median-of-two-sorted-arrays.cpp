class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(int i= 0 ; i<nums2.size(); i++){
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(), nums1.end());
        if(nums1.size()%2!=0){
            int ub= nums1.size();
            int mid=ub/2;
            return static_cast<double>(nums1[mid]);
        } else{
            int l=0;
            int u=nums1.size();
            int m=(u+l)/2;
             return ((static_cast<double>(nums1[m])+static_cast<double>(nums1[m-1]))/2.0);
           
        }
        return 0;
    }
};