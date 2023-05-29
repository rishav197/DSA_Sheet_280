/* TC->O(N), SC->O(N)*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minPrice = INT_MAX;
        int ans=0;

        for(int idx=0; idx<n; ++idx){
            minPrice = min(minPrice, prices[idx]);
            if((prices[idx]-minPrice)>ans){
                ans = prices[idx]-minPrice;
            }
        }
        return ans;
    }
};