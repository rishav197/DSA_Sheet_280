/*Approach - two pointer approach; TC->O(N); SC->O(1)*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int mxArea = 0; //becoz area can't be -ve

        int lo=0;
        int hi=n-1;
        while(lo<hi){
            int wi = hi-lo;
            if(height[lo]<height[hi]){
                mxArea = max(mxArea, wi*min(height[lo], height[hi]));
                ++lo;
            }
            else{
                mxArea = max(mxArea, wi*min(height[lo], height[hi]));
                --hi;
            }
            
        }

        return mxArea;

    }
};