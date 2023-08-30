#include <bits/stdc++.h>
using namespace std;


class Stack{
    deque<int> dq;
    int N;
public:
    Stack(){
        N=0;
    }
    void push(int val){
        dq.push_back(val);
        N++;
    }

    void pop(){
        dq.pop_back();
        N--;
    }

    int top(){
        return dq.back();
    }

    int size(){
        return N;
    }

};


class Queue{
    deque<int> dq;
    int N;
public:
    Queue(){
        N=0;
    }
    void push(int val){
        dq.push_back(val);
        N++;
    }

    void pop(){
        dq.pop_front();
        N--;
    }

    int peek(){
        return dq.front();
    }

    int size(){
        return N;
    }

};


int main(){

    /* for Stack */

    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    cout<<st.top()<<endl;

    st.pop();
    st.pop();

    cout<<st.top()<<endl;
    cout<<st.size()<<endl;

    st.pop();
    st.pop();

    cout<<st.size()<<endl;


    /* for Queue */
    Queue qu;
    qu.push(100);
    qu.push(110);
    qu.push(120);
    qu.push(130);
    qu.push(140);

    cout<<qu.peek()<<endl;
    qu.pop();
    qu.pop();
    qu.pop();

    cout<<qu.peek()<<endl;
    cout<<qu.size()<<endl;


    return 0;
}