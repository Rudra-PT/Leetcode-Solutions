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
    int pairSum(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        slow->next = nullptr;  

    while (curr != nullptr) {
        ListNode* nextNode = curr->next; 
        curr->next = prev;             
        prev = curr;                
        curr = nextNode;          
    }
    int maxVal = 0 ;
    ListNode* first = head;
    ListNode* second = prev;

    while(second != NULL){
        int sum = first->val + second->val;
        maxVal = max(sum , maxVal);
        first = first->next;
        second = second->next;
    }

        return maxVal;
    
    }
};