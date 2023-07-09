/* 
    TC->O(max(len(list1),len(list2))); SC->O(1)
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ptr1=list1;
        ListNode* ptr2=list2;

        ListNode* dummyNode=new ListNode(-1);
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
};


/*Approach-2: Recursive approach */
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //base case
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }

        ListNode* result;
        if(list1->val<list2->val){
            result=list1;
            result->next=mergeTwoLists(list1->next,list2);
        }
        else{
            result=list2;
            result->next=mergeTwoLists(list1,list2->next);
        }

        return result;
    }
};