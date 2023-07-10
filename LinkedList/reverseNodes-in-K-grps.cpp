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
    ListNode* reverseK(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }

        ListNode* prevptr=NULL;
        ListNode* currptr=head;
        ListNode* nextptr;

        ListNode* tmp=head;
        for(int i=0; i<k; ++i){
            if(tmp==nullptr){
                return head;
            }
            tmp=tmp->next;
        }

        int cnt=1;
        while(currptr!=NULL and cnt<=k){
            nextptr=currptr->next;
            currptr->next=prevptr;

            prevptr=currptr;
            currptr=nextptr;
            cnt++;
        }

        if(nextptr!=NULL){
            head->next=reverseK(nextptr,k);
        }

        return prevptr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* newhead=reverseK(head,k);
        return newhead;
    }
};