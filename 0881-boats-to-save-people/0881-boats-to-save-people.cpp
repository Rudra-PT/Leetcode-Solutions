class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boatCount = 0 ;
        int n = people.size();
        sort(people.begin() , people.end());
        int i = 0 ; 
        int j = n-1 ;
        while(i<=j){
            if(people[i]+people[j] > limit){
                j--;
                boatCount ++;
            }
            else if(people[i]+people[j] < limit){
                i++;
                j--;
                boatCount ++;
            } else{
                i++;
                j--;
                boatCount ++;
            }

        }

            return boatCount;
    }
};