/* Approach-1: Cumulative sum approach; TC->O(N^2), SC->O(N+1)*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        int currSum[n+1];
        currSum[0]=0;
        int count=0;
        for(int i=1; i<=n; ++i){
            currSum[i] = currSum[i-1] + nums[i-1];
        }
        for(int i=0; i<=n; ++i){
            int sum = 0;
            for(int j=0; j<i; ++j){
                sum = currSum[i]-currSum[j];
                if(sum==k){
                    ++count;
                }
            }
        }
        return count;

    }
};




/*Approach-2: Prefix sum with map TC->O(N); SC->O(N)*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0){
            return 0;
        }

        unordered_map<int,int> map;
        int currSum = 0;
        int idx=0;
        int count = 0;
        while(idx<n){
            currSum += nums[idx];
            if(currSum == k){
                count+=1;
            }
            if(map.find(currSum-k)!=map.end()){ //when currSum-k is present
                count+=map[currSum-k];
            }
            map[currSum]+=1;
            ++idx;
        }
        return count;
    }
};