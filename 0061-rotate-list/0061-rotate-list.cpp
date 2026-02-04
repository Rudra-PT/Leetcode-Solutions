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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        vector<int> tempArr;
        ListNode* temp = head;
        while(temp != NULL){
            tempArr.push_back(temp->val);
            temp = temp->next;
        }
        int n = tempArr.size();
        k = k % n; 
        if (k == 0) return head;
        reverse(tempArr.begin(), tempArr.end());
        reverse(tempArr.begin(), tempArr.begin() + k);
        reverse(tempArr.begin() + k, tempArr.end());

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        
        for(int val : tempArr) {
            curr->next = new ListNode(val);
            curr = curr->next;
        }

        return dummy->next;
    }
};