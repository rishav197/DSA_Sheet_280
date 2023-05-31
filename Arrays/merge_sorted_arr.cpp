/* Approach-1: TC->O(NlongN), SC->O(N)*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int idx=m;
        for(int i=0; i<n; ++i){
            nums1[idx++]=nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};

/*Approach-2: TC->O(N), SC->O(1)*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int k=m+n-1;

        while(i>=0 && j>=0){
            nums1[k--] = (nums1[i]<nums2[j]) ? nums2[j--] : nums1[i--];
        }
        while(j>=0){
            nums1[k--] = nums2[j--];
        }
    }
};