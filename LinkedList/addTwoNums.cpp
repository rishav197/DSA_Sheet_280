/*TC-> O(max(l1,l2)); */

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
    void insertAtTail(ListNode* &head, int val){
        ListNode* newNode=new ListNode(val);
        ListNode* tmp=head;
        tmp->next=newNode;

    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3=new ListNode(0);
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
        return dummyHead->next;
    }
};