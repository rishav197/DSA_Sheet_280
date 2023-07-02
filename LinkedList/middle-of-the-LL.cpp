/* 
T.C -> O(N); 
S.C->O(1)
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
    ListNode* middleNode(ListNode* head) {
        if(head==NULL){
            return head;
        }
        ListNode* tmp = head;
        int n = 0;
        while(tmp!=NULL){
            n+=1;
            tmp=tmp->next;
        }
        // cout<<n<<endl;
        tmp = head;
        int midIdx = n/2;
        int idx=1;
        while(idx<=midIdx){
            tmp = tmp->next;
            idx++;
        }
        
        return tmp;
    }
};