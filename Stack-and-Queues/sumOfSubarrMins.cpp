/*
Approach: Bruteforce 
*/

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n =arr.size();
        long long sum=0;
        vector<int> arrofmins;
        int M = 1e9+7; //modulo

        for(int idx1=0; idx1<n; idx1++){
            for(int idx2=idx1; idx2<n; idx2++){
                // cout<<idx1<<" "<<idx2<<endl;
         
                int mn=9999999999;

                for(int idx=idx1; idx<=idx2; idx++){
                    if(arr[idx]<mn){
                        mn=arr[idx];
                    }
                }
                cout<<mn<<endl;
                sum=(sum+mn)%M;
            }
        }

        return sum;
    }
};




/*
Approach: Using Stack based on concept of NSL and NSR.
NSL -> Next Smaller to left
NSR -> Next Smaller to right
*/
class Solution {
public:
    vector<int> getNSL(vector<int>& arr, int n){
        vector<int> rslt(n);
        stack<int> st;

        for(int idx=0; idx<n; idx++){
            if(st.empty()){
                rslt[idx]=-1;
            }
            else{
                while(!st.empty() and arr[st.top()]>=arr[idx]){
                    st.pop();
                }
                rslt[idx] = st.empty()? -1 : st.top();
            }
            st.push(idx);
        }

        return rslt;
    }

    vector<int> getNSR(vector<int>& arr, int n){
        vector<int> rslt(n);
        stack<int> st;

        for(int idx=n-1; idx>=0; idx--){
            if(st.empty()){
                rslt[idx]=n;
            }
            else{
                while(!st.empty() and arr[st.top()]>arr[idx]){
                    st.pop();
                }
                rslt[idx] = st.empty() ? n : st.top();
            }
            st.push(idx);
        }

        return rslt;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> NSL = getNSL(arr,n);
        vector<int> NSR = getNSR(arr,n);

        long long sum = 0;
        int M = 1e9+7; //modulo

        for(int idx=0; idx<n; idx++){
            long long ls = idx-NSL[idx]; //no. of eles in the left side
            long long rs = NSR[idx]-idx; //no. of eles in the right side

            long long totalWays=ls*rs;
            //totalWays in subarrays having min arr[idx]

            long long totalSum = arr[idx]*totalWays;
            sum = (sum + totalSum)%M;
        }

        return sum;
    }
};