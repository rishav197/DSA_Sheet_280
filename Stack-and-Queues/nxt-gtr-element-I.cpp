/* 
TC-> O(N)
SC-> O(N)
*/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map;
        stack<int> st;

        for(int idx=nums2.size()-1; idx>=0; --idx){
            while(!st.empty() and nums2[idx]>st.top()){
                st.pop();
            }
            map[nums2[idx]] = (!st.empty()) ? st.top() : -1;

            st.push(nums2[idx]);
        }

        for(int idx=0; idx<nums1.size(); ++idx){
            nums1[idx]=map[nums1[idx]];
        }
        return nums1;
    }
};