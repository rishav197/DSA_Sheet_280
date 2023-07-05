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
    int getDecimalValue(ListNode* head) {
        if(head->next==NULL){
            return head->val;
        }
    
        ListNode* tmp=head;
        int cnt=0;
        while(tmp!=NULL){
            cnt++;
            tmp=tmp->next;
        }

        tmp=head;
        int sum=0;
        while(tmp!=NULL){
            sum+=(tmp->val)*pow(2,cnt-1);
            tmp=tmp->next;
            cnt--;
        }

        return sum;
    }
};