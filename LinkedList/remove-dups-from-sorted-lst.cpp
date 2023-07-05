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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL or head->next==NULL){
            return head;
        }

        ListNode* tmp1=head;
        ListNode* tmp2;

        while(tmp1!=NULL and tmp1->next!=NULL){
            tmp2=tmp1->next;
            if(tmp1->val==tmp2->val){
                ListNode* todelete=tmp2;
                tmp1->next=tmp2->next;
                tmp2->next=NULL;
                delete todelete;
                tmp2=tmp1->next;
            }
            else{
                tmp1=tmp1->next;
            }
            
        }

        return head; 
    }
};