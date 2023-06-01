/*approach-1: TC->O(N^2), SC-O(1) */
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        long long ans=0;
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){   
                if(nums[i]>(long long)2*nums[j])
                    ++ans;
            }
        }

        return ans;
    }
};

/* approach-2: using merge Sort; TC->O(NlogN), SC->O(N) */
class Solution {
public:
    void merge(vector<int>&nums,int lo,int mi,int hi,int &ans){
        int i=lo;
        int j=mi+1;
        int r=j;
        int count=0;
        vector<int> vect;
        while(i<=mi){
            while(r<=hi and nums[i]>(long long)2*nums[r]){
                ++count;
                ++r;
            }
            ans+=count;
            while(j<=hi and nums[j]<=nums[i]){
                vect.push_back(nums[j++]);
            }
            vect.push_back(nums[i++]);
        }
        while(j<=hi){
            vect.push_back(nums[j++]);
        }
        for(int i=lo; i<=hi; ++i){
            nums[i]=vect[i-lo];
        }
    }

    void mergeSort(vector<int> &nums, int lo, int hi, int &ans){
        if(lo>=hi)
            return;
        int mi=lo+(hi-lo)/2;
        mergeSort(nums,lo,mi,ans);
        mergeSort(nums,mi+1,hi,ans);
        merge(nums,lo,mi,hi,ans);
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        mergeSort(nums,0,n-1,ans);

        return ans;
    }
};