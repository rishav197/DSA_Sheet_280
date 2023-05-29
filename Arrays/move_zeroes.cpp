class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int nonzero=0;
        for(int idx=0; idx<n; ++idx){
            if(nums[idx]!=0){ //non-zero num
                nums[nonzero] = nums[idx];
                nonzero+=1;
            }
        }

        while(nonzero<n){
            nums[nonzero] = 0;
            nonzero+=1;
        }
    }
}; 