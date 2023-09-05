class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    
        //move (Right->Left)
        stack<int> st;
        for(int idx=0; idx<tokens.size(); idx++){

            string ch=tokens[idx];
            if(ch=="+" or ch=="-" or ch=="*" or ch=="/"){//when is a operator
                int operand1=st.top();
                st.pop();
                int operand2=st.top();
                st.pop();

                if(ch=="/"){
                    st.push(operand2/operand1);
                }
                else if(ch=="*"){
                    st.push(operand2*operand1);
                }
                else if(ch=="+"){
                    st.push(operand2+operand1);
                }
                else if(ch=="-"){
                    st.push(operand2-operand1);
                }

            }
            else{ //when ele is a num
                st.push(stoi(ch));
            }
        }

        return st.top();;
    }
};