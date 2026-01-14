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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        vector<int> ans;
        for (int i = 0 ; i < n ; i++){
            ListNode* temp = lists[i]; 
            while(temp != NULL){
                ans.push_back(temp->val);
                temp = temp->next;
            }
        }
        
        sort(ans.begin() , ans.end());
        ListNode* dummy = new ListNode(0);
        ListNode* poi = dummy;
        
        for(int j = 0 ; j < ans.size() ; j++){
            ListNode* newNode = new ListNode(ans[j]);
            poi->next = newNode;
            poi = poi->next;
        }
        
        return dummy->next;
    }
};