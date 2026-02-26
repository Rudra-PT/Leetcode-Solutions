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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans(k , nullptr);
        if(head == NULL) return ans;

        int listLen = 0;
        ListNode* temp = head;
        while(temp != NULL){
              listLen++;
            temp = temp->next;
        }
        int baseSize =listLen/k;
        int extraNodes = listLen %k ;
        temp = head;

        for(int i = 0 ; i< k && temp!= NULL ; i++){
            ans[i] = temp;
            int currentPartSize = baseSize + (extraNodes > 0 ? 1 : 0);
            extraNodes--; 

            for(int j = 1 ; j<currentPartSize; j++){
                temp = temp->next;
            }
            ListNode*nextPart = temp->next;
            temp->next = nullptr;
            temp = nextPart;
        }
        return ans;
    }
};