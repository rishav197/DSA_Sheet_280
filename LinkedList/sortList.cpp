/* TC-O(nlogn), SC->O(N)
*/
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
    ListNode* sortList(ListNode* head) {
        if(head==NULL or head->next==NULL){
            return head;
        }
        

        ListNode* tmp=head;
        vector<int> vect={};
        while(tmp!=NULL){
            vect.push_back(tmp->val);
            tmp=tmp->next;
        }
        sort(vect.begin(),vect.end());

        int idx=0;
        tmp=head;
        while(tmp!=NULL){
            tmp->val=vect[idx++];
            tmp=tmp->next;
        }

        return head;

    }
};