/* TC->O(N), SC->O(N)*/
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

        ListNode* newHead = reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return newHead;
    }

    void reorderList(ListNode* head) {
        ListNode* tmp=head;
        int n=0;
        while(tmp!=NULL){
            tmp=tmp->next;
            n+=1;
        }
        cout<<n<<endl;

        int m=(n%2==0) ? n/2: n/2+1;
        cout<<m<<endl;

        tmp=head;
        ListNode* head2;
        int cnt=1;
        while(tmp!=NULL and cnt!=m){
            tmp=tmp->next;
            cnt++;
        }

        head2=tmp->next;
        tmp->next=NULL;

        head2=reverse(head2);
        //Now, we have two lists with heads head & head2
        ListNode* tmp1=head;
        ListNode* tmp2=head2;
        ListNode* dummyNode=new ListNode(-1);
        ListNode* dptr=dummyNode;
        while(tmp1!=NULL and tmp2!=NULL){
            dptr->next=tmp1;
            dptr=dptr->next;
            tmp1=tmp1->next;

            dptr->next=tmp2;
            dptr=dptr->next;
            tmp2=tmp2->next;
        }

        while(tmp1!=NULL){
            dptr->next=tmp1;
            tmp1=tmp1->next;
        }

        head=dummyNode->next;
    }
};