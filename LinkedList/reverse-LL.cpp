/* 
    TC-> O(N); SC->O(N)
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
    ListNode* reverseRecursive(ListNode* &head){
        if(head==NULL or head->next==NULL){
            return head;
        }

        ListNode* newHead = reverseRecursive(head->next);
        head->next->next=head;
        head->next=NULL;
        return newHead;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* newHead=reverseRecursive(head);
        return newHead;
    }
};