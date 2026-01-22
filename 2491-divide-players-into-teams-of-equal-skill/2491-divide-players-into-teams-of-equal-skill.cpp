class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int n = skill.size();
        int i = 0;
        int j = n - 1;
        
        long long totalChemistry = 0;
        int targetSum = skill[i] + skill[j];

        while (i < j) {
            if (skill[i] + skill[j] != targetSum) {
                return -1;
            }
            totalChemistry += (long long)skill[i] * skill[j];
            i++;
            j--;
        }
        
        return totalChemistry;
    }
};