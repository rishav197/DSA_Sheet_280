/* Approach-1: Bruteforce; TC->O(N^3) */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0; i<n-2; ++i){
            for(int j=i+1; j<n-1; ++j){
                for(int k=j+1; k<n; ++k){
                    // cout<<i<<" "<<j<<" "<<k<<endl;
                    if((nums[i]+nums[j]+nums[k]==0) && i!=j && j!=k && k!=i){
                        s.insert({nums[i], nums[j], nums[k]});
                    }
                }
                
            }
        }
        
        for(auto idx : s){
            ans.push_back(idx);
        }

        return ans;
    }
};


/*Approach-2: two pointer approach, TC->O(N^2)*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        set<vector<int>> s;


        for(int i=0; i<n-2; ++i){
            int lo = i+1;
            int hi = n-1;
            while(lo<hi){
                if(nums[i]+nums[lo]+nums[hi]<0){
                    ++lo;
                }
                else if(nums[i]+nums[lo]+nums[hi]>0){
                    --hi;
                }
                else{
                    s.insert({nums[i],nums[lo],nums[hi]});
                    ++lo;
                    --hi;
                }
            }
        }

        for(auto vects : s){
            ans.push_back(vects);
        }
        return ans;
    }
};