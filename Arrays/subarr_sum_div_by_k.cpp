/* Approach: three nested loop; TC->O(N^3), SC->O(1)*/
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        for(int i=0; i<n; ++i){
            for(int j=i; j<n; ++j){
                int sum = 0;
                for(int m=i; m<=j; ++m){
                    sum += nums[m];
                }
                if(sum%k==0)
                    ++ans;
            }
        }
        return ans;
    }
};



/* Approach: Cumulative Sum approach; TC->O(N^2), SC->O(1)*/
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int currSum[n+1];
        currSum[0]=0;
        int ans=0;

        for(int idx=1; idx<=n; ++idx){
            currSum[idx] = currSum[idx-1]+ nums[idx-1];
        }

        int mxSum = INT_MIN;
        for(int i=1; i<=n; ++i){
            int sum = 0;
            for(int j=0; j<i; ++j){
                sum = currSum[i]-currSum[j];
                if(sum%k==0){
                    ++ans;
                }  
            }
        }
        return ans;
    }
};