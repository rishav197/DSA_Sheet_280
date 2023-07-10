
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
    }

    ListNode* merge(ListNode* &head1, ListNode* &head2){
        ListNode* ptr1=head1;
        ListNode* ptr2=head2;

        ListNode* dummyNode=new ListNode(-99999);
        ListNode* dummyhead=dummyNode;

        while(ptr1!=NULL and ptr2!=NULL){
            if(ptr1->val<ptr2->val){
                dummyNode->next=ptr1;
                ptr1=ptr1->next;
            }
            else{
                dummyNode->next=ptr2;
                ptr2=ptr2->next;
            }
            dummyNode=dummyNode->next;
        }

        //when we're not at the end of list1
        while(ptr1){
            dummyNode->next=ptr1;

            ptr1=ptr1->next;
            dummyNode=dummyNode->next;
        }

        //when we're not at the end of list2
        while(ptr2){
            dummyNode->next=ptr2;

            ptr2=ptr2->next;
            dummyNode=dummyNode->next;
        }

        return dummyhead->next; //returning head of final node
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0){
            return NULL;
        }
        if(n==1){
            return lists[0];
        }
        
        ListNode* head=merge(lists[0],lists[1]);
        if(n==2){
            return head;
        }

        for(int idx=2; idx<n; ++idx){
            head=merge(head,lists[idx]);
        }

        return head;
    }
};