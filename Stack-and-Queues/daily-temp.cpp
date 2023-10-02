class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans;
        stack<int> st;
        int n = temperatures.size();
        // cout<<n<<endl;

        //moving from right to left of the temperatures[] array
        for(int idx=n-1; idx>=0; --idx){
            if(st.empty()){
                st.push(idx);
                ans.push_back(0);
            }
            else{
                //when stack is filled 
                while(!st.empty() and temperatures[st.top()]<=temperatures[idx]){
                    st.pop();
                }

                if(st.empty()){
                    st.push(idx);
                    ans.push_back(0);
                }
                else{
                    ans.push_back(st.top()-idx);
                    st.push(idx);
                }
            }
        }


        reverse(ans.begin(), ans.end()); //reversing ans vector
        return ans;
    }
};