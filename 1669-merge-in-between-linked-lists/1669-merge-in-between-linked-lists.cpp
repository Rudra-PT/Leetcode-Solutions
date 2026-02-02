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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prevA = list1;
        for(int i = 0; i < a - 1; i++) {
            prevA = prevA->next;
        }
        ListNode* nodeB = prevA; 
        for(int i = 0; i < b - a + 1; i++) {
            nodeB = nodeB->next;
        }
        
        ListNode* list2Tail = list2;
        while(list2Tail->next) {
            list2Tail = list2Tail->next;
        }
        prevA->next = list2;      
        list2Tail->next = nodeB->next;
        
        return list1;
    }
};