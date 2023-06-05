class Solution {
public:
    bool isValid(string s) {
        if(s.length()==1){
            return false;
        }

        stack<int> st;
        int n = s.length();
        
        bool ans = true;
        int i=0;
        while(i<n){
            if(s[i]=='(' or s[i]=='[' or s[i]=='{'){
                char ch = s[i];
                st.push(ch);
            }
            else{ //encounter close bracks->),],}
                if(s[i]==')'){
                    if(!st.empty() and st.top()=='('){
                        st.pop();
                    }
                    else{
                        ans=false; break;
                    }
                }
                else if(s[i]=='}'){
                    if(!st.empty() and st.top()=='{'){
                        st.pop();
                    }else{
                        ans=false; break;
                    }

                }
                else if(s[i]==']'){
                    if(!st.empty() and st.top()=='['){
                        st.pop();
                    }else{
                        ans=false; break;
                    }
                }
            }
            ++i;
        }

        if(!st.empty()){
            return false;
        } 
        return ans;
    }
};