class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        int arr[n];
        for(int i=0; i<n; ++i){
            arr[i]=-1;
        }
        
        for(int i=0; i<n; ++i){
            arr[nums[i]] += 1;
        }

        int ans;
        for(int i=0; i<n; ++i){
            // cout<<arr[i]<<" ";
            if(arr[i]>0){
                ans = i;
            }
        }

        return ans;
    }
};