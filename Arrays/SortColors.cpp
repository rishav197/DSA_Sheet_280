#include<bits/stdc++.h>

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int count=1;
        while(count<n){
            for(int i=0; i<n-count; i++){
                if(nums[i]>nums[i+1]){
                    int temp=nums[i];
                    nums[i]=nums[i+1];
                    nums[i+1]=temp;
                }
            }
            count++;
        }   
    }
};