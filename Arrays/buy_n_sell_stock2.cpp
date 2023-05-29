/* TC->O(N), SC-O(1)*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        for(int idx=0; idx+1<n; ++idx){
            if(prices[idx+1]-prices[idx]>0){
                ans += prices[idx+1]-prices[idx];
            }
        }
        return ans;
    }
};