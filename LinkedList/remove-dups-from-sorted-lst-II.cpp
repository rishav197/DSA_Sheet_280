/* TC->(NlogN); SC->O(logn)*/
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
        ListNode* tmp=head;
        map<int,int> mp;

        while(tmp!=NULL){
            mp[tmp->val]++;
            tmp=tmp->next;
        }

        ListNode* dummyNode=new ListNode(-1);
        ListNode* dptr=dummyNode;
        for(auto i:mp){
            if(i.second==1){
                ListNode* newNode=new ListNode(i.first);
                dptr->next=newNode;
                dptr=dptr->next;
            }
        }

        return dummyNode->next;
    }
};