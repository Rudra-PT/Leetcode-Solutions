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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*count = head;
        int len = 0 ;
        while(count != NULL){
            count = count->next;
            len++;
        }
        if(len == n){
            head = head->next;
            return head;
        }
        ListNode*temp = head;
        int steps = (len - n) -1;
        while(steps>0){
            temp = temp->next;
            steps--;
        }
        temp ->next = temp->next->next;
        return head;
    }
};