class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        set<vector<int>> st;

        for(int i=0; i<n-3; ++i){
            for(int j=i+1; j<n-2; ++j){
                int lo=j+1;
                int hi=n-1;
                while(lo<hi){
                    long long newTarget = (long long)target - (nums[i]+nums[j]);
                    if(nums[lo]+nums[hi]<newTarget){
                        ++lo;
                    }
                    else if(nums[lo]+nums[hi]>newTarget){
                        --hi;
                    }
                    else{
                        st.insert({nums[i],nums[j],nums[lo],nums[hi]});
                        ++lo;
                        --hi;
                    }
                }
            }
        }


        for(auto vects : st){
            ans.push_back(vects);
        }
        return ans;

    }
};