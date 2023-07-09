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
    ListNode* reverse(ListNode* &head){
        if(head==NULL or head->next==NULL){
            return head;
        }

        ListNode* newhead=reverse(head->next);
        head->next->next=head;
        head->next=NULL;

        return newhead;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverse(l1);
        l2=reverse(l2);

        ListNode* l3=new ListNode(-1);
        ListNode* dummyHead=l3;
        int carry=0;
        while(l1 and l2){
            int val=l1->val+l2->val+carry;
            l3->next=new ListNode(val%10);
            carry=val/10;
            l3=l3->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            int val=l1->val+carry;
            l3->next=new ListNode(val%10);
            carry=val/10;
            l3=l3->next;
            l1=l1->next;
        }
        while(l2){
            int val=l2->val+carry;
            l3->next=new ListNode(val%10);
            carry=val/10;
            l3=l3->next;
            l2=l2->next;
        }
        if(carry){
            l3->next=new ListNode(carry);
        }
        
        ListNode* head=reverse(dummyHead->next);
        return head;
    }
};