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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int>arr;
        ListNode* temp = head;
        while(temp !=NULL){
            arr.push_back(temp->val);
            temp =temp->next;
        }
        int n = arr.size();
        int i = k-1; 
        int j = n-k;

        swap(arr[i], arr[j]);

        temp = head;
        for(int m = 0 ; m<n; m++){
            temp->val= arr[m];
            temp = temp->next;

        }
        return head;

    }
};