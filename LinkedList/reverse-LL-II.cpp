/*TC->O(N), SC->O(right-left+1)*/
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

    ListNode* reverse(ListNode* &head){
        if(head==NULL or head->next==NULL){
            return head;
        }

        ListNode* newHead = reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return newHead;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL or head->next==NULL){
            return head;
        }

        ListNode* dummyNode=new ListNode(-1);
        ListNode* dptr=dummyNode;


        ListNode* tmp=head;
        int cnt=1;
        while(tmp!=NULL){
            if(cnt>=left and cnt<=right){
                // cout<<tmp->val<<" ";
                dptr->next=new ListNode(tmp->val);
                dptr=dptr->next;
            }
            tmp=tmp->next;
            cnt++;
        }

        // prt(dummyNode->next);
        ListNode* newhead=reverse(dummyNode->next);
        // prt(newhead);

        //now, copying eles from reversed sub-list to the original list
        tmp=head;
        cnt=1;
        while(tmp!=NULL){
            if(cnt>=left and cnt<=right){
                tmp->val=newhead->val;
                newhead=newhead->next;
            }
            tmp=tmp->next;
            cnt++;
        }

        return head;
    }
};