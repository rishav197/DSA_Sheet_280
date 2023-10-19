class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();

        stack<char> st;
        for(int idx=0; idx<n; ++idx){
            if(st.empty()){
                st.push(s[idx]);
            }
            else{
                if(s[idx]==st.top()){
                    st.pop();
                }
                else{
                    st.push(s[idx]);
                }
            }
        }

        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }

        return ans;
    }
};