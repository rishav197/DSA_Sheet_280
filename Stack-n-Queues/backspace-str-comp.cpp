/* 
TC-O(N), SC-O(N) 
*/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        stack<char> st2;
        if(s.length()==0 and t.length()==0){
            return true;
        }

        for(int idx=0; idx<s.length(); ++idx){
            if(s[idx]=='#'){
                if(!st1.empty()){
                    st1.pop();
                }
            }else{
                st1.push(s[idx]);
            }
        }

        for(int idx=0; idx<t.length(); ++idx){
            if(t[idx]=='#'){
                if(!st2.empty()){
                    st2.pop();
                }
            }else{
                st2.push(t[idx]);
            }
        }

        string s1="";
        string s2="";
        while(!st1.empty()){
            s1=st1.top()+s1;
            st1.pop();
        }
        while(!st2.empty()){
            s2=st2.top()+s2;
            st2.pop();
        }

        // cout<<s1<<endl;
        // cout<<s2<<endl;
        if(s1==s2){
            return true;
        }   
        return false;     
    }
};