/* Approach: Sliding window approach; TC-O(N), SC-O(1) */

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int ans = 0;
        for(int idx=0; idx<k; ++idx){
            ans += cardPoints[idx];
        }

        int tmp = ans;
        for(int i=k-1; i>=0; i--){
            tmp -= cardPoints[i]; //shift at start of the arr
            tmp += cardPoints[n-k+i]; //shift at end of the arr
            ans = max(ans, tmp);
        }
        return ans;
        
    }
};