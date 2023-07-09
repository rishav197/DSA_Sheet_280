/*TC->O(N); SC->O(1)*/
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
        if(head->next==NULL and n==1){
            return NULL;
        }
        int N=0;
        ListNode* tmp=head;
        while(tmp!=NULL){
            tmp=tmp->next;
            N++;
        }

        int m=N-n+1;
        cout<<m<<endl;
        if(m==1){
            return head->next;
        }
        tmp=head;
        int cnt=1;
        while(tmp->next!=NULL and cnt!=m-1){
            tmp=tmp->next;
            cnt++;
        }
        // cout<<tmp->val<<endl;
        ListNode* todelete=tmp->next;
        if(tmp->next!=NULL){
            tmp->next=tmp->next->next;
        }
        delete todelete;

        return head;
    }
};