/*  
TC->O(N); 
*/
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        stack<int> st;
        
        for(int idx=0; idx<S.length(); ++idx){
            if(S[idx]>='0' and S[idx]<='9'){
                st.push(S[idx]-'0');
            }
            else{ //opr is being encounter
                int op2=st.top();
                st.pop();
                int op1=st.top();
                st.pop();                
                
                if(S[idx]=='+'){
                    st.push(op1+op2);
                }
                else if(S[idx]=='-'){
                    st.push(op1-op2);
                }
                else if(S[idx]=='*'){
                    st.push(op1*op2);
                }
                else if(S[idx]=='/'){
                    st.push(op1/op2);
                }
            }
        }
        
        return st.top();
    }
};