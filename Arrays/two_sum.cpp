/* TC->O(Nlog(N)), SC->O(N) */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> ans;
        for(int idx=0; idx<nums.size(); ++idx){
            int rslt = target-nums[idx];
            if(map.find(rslt) != map.end()){
                ans.push_back(map[rslt]);
                ans.push_back(idx);
            }
            map[nums[idx]]=idx;

        }
        return ans;
    }
};