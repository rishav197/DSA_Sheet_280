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
    void prt(ListNode* head){
        ListNode* tmp=head;
        while(tmp!=NULL){
            cout<<tmp->val<<" ";
            tmp=tmp->next;
        }
        cout<<endl;
    }

    ListNode* partition(ListNode* head, int x) {
        if(head==NULL or head->next==NULL){
            return head;
        }


        ListNode* dummyHead=new ListNode(-1);
        ListNode* dptr=dummyHead;

        ListNode* dummyHead2=new ListNode(-2);
        ListNode* dptr2=dummyHead2;

        ListNode* tmp=head;
        while(tmp!=NULL){
            // cout<<tmp->val<<" ";
            if(tmp->val<x){
                dptr->next=new ListNode(tmp->val);
                dptr=dptr->next;
            }
            else{
                dptr2->next=new ListNode(tmp->val);
                dptr2=dptr2->next;
            }
            tmp=tmp->next;
        }
        // cout<<tail->val<<endl;

        dptr->next=dummyHead2->next;
        // prt(dummyHead->next);

        return dummyHead->next;
    }
};