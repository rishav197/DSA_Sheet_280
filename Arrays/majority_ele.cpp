/* Approach-1: TC->O(N), SC-O(N) */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> map;

        for(int i=0; i<n; ++i){
            if(map.find(nums[i])!=map.end()){
                ++map[nums[i]];
            }
            else{
                map[nums[i]]=0;
            }
        }

        int ans=0;
        int N = n/2;
        for(int idx=0; idx<n; ++idx){
            if(map[nums[idx]]>=N){
                ans=nums[idx];
            }
        }

        return ans;
    }
};


/* Approach-2: TC->O(nlogn), SC->O(1) */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int lo=0;
        int hi=n-1;
        int mi=lo+(hi-lo)/2;
        return nums[mi];

    }
};