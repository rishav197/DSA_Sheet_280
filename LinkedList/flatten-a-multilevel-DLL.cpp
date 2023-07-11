/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr=head;
        Node* tail=head;
        stack<Node*> st;

        while(curr!=NULL){
            if(curr->child!=NULL){
                if(curr->next!=NULL){
                    Node* nx=curr->next;
                    nx->prev=NULL;
                    st.push(nx);
                }

                //dealing with childrens
                Node* child=curr->child;
                curr->next=child;
                child->prev=curr;
                curr->child=NULL;
            }
            tail=curr;
            curr=curr->next;
        }

        //now, we need to add lists which are stored in the stack to the end of above list.
        while(!st.empty()){
            curr=st.top();
            tail->next=curr;
            curr->prev=tail;

            while(curr!=NULL){
                tail=curr;
                curr=curr->next;
            }
            st.pop();
        }

        return head;
    }
};