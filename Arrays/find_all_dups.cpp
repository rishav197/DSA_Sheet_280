/* TC->O(N), SC->O(N) */

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        int check[n+1];
        vector<int> ans;

        for(int idx=0; idx<n+1; ++idx){
            check[idx]=-1;
        }

        for(int idx=0; idx<n; ++idx){
            check[nums[idx]]+=1;
        }

        for(int idx=1; idx<n+1; ++idx){
            if(check[idx]==1)
                ans.push_back(idx);
        }

        return ans;

    }
};