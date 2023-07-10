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
        ListNode* temp=head;
        while(temp!=NULL){
            if(temp!=NULL){
                cout<<" ";
            }
            cout<<temp->val;
            temp=temp->next;
        }
    }

    ListNode* reverseRecursive(ListNode* &head){
        if(head==NULL or head->next==NULL){
            return head;
        }

        ListNode* newHead = reverseRecursive(head->next);
        head->next->next=head;
        head->next=NULL;

        return newHead;
    }

    bool isPalindrome(ListNode* head) {
        if(head==NULL or head->next==NULL){
            return true;
        }
        ListNode* tmp1=head;
        string s1="";
        while(tmp1!=NULL){
            // cout<<tmp1->val<<" ";
            s1+=to_string(tmp1->val);
            tmp1=tmp1->next;
        }
        cout<<s1<<endl;

        ListNode* newhead= reverseRecursive(head);
        ListNode* tmp2=newhead;
        string s2="";
        while(tmp2!=NULL){
            // cout<<tmp1->val<<" ";
            s2+=to_string(tmp2->val);
            tmp2=tmp2->next;
        }
        cout<<s2<<endl;
        if(s1==s2){
            return true;
        }
        return false;
    }
};