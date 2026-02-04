/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        if (!head || !head->next || !head->next->next) return {-1, -1};

        ListNode* prev = head;
        ListNode* curr = head->next;
        int currentIndex = 2;
        
        int firstCriticalIndex = 0;
        int prevCriticalIndex = 0;
        
        int minDistance = INT_MAX;

        while (curr->next != NULL) {
            if ((curr->val > prev->val && curr->val > curr->next->val) || 
                (curr->val < prev->val && curr->val < curr->next->val)) {
                
                if (firstCriticalIndex == 0) {
                    firstCriticalIndex = currentIndex;
                } else {
                    minDistance = min(minDistance, currentIndex - prevCriticalIndex);
                }
            
                prevCriticalIndex = currentIndex;
            }

            prev = curr;
            curr = curr->next;
            currentIndex++;
        }
        if (minDistance == INT_MAX) return {-1, -1};

        int maxDistance = prevCriticalIndex - firstCriticalIndex;
        return {minDistance, maxDistance};
    }
};