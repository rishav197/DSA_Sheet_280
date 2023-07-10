//User function template for C++
/* TC->O(N); SC->O(N)*/
/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        Node* tmp=head;
        
        vector<int> oddlst;
        vector<int> evenlst;
        while(tmp!=NULL){
            if(tmp->data%2==1){
                oddlst.push_back(tmp->data);
            }
            else{
                evenlst.push_back(tmp->data);
            }
            tmp=tmp->next;    
        }

        //copy elements from oddlst & evenlst to given lst 
        tmp=head;
        for(int i=0; i<evenlst.size(); ++i){
            tmp->data=evenlst[i];
            tmp=tmp->next;
        }
        
        for(int i=0; i<oddlst.size(); ++i){
            tmp->data=oddlst[i];   
            tmp=tmp->next;
        }
        
        return head;
    }
};