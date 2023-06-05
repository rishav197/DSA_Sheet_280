/* TC->O(N^2), SC->O(1) */
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        long long mx = -9223372036854775808;

        for(int i=0; i<n; ++i){
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j=i+1; j<n; ++j){
                int x2 = points[j][0];
                int y2 = points[j][1];
                long long result = (long long)((y1+y2) + abs(x1-x2));
                if(abs(x1-x2)<=k)
                    mx = max(mx, result);
            }
        }

        return mx;
    }
};