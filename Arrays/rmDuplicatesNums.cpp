#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        set<int> lst;

        for(int i=0; i<n; ++i){
            lst.insert(nums[i]);
        }

        int idx=0;
        for(auto i : lst) {
            // cout << i << ' ';
            nums[idx]=i;
            ++idx;
        }
        auto it = nums.begin();
        nums.erase(it+lst.size(), it+n);

        return lst.size();
    }
};