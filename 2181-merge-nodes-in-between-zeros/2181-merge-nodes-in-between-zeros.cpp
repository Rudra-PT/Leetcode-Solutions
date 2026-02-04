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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* write = head; 
        ListNode* temp = head->next; 
        int sum = 0;

        while(temp != NULL) {
            if(temp->val != 0) {
                sum += temp->val;
            } else {
                write = write->next;
                write->val = sum;
                sum = 0;
            }
            temp = temp->next;
        }
        
        write->next = NULL;
        return head->next;
    }
};