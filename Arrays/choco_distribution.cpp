//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* TC->O(N), SC->O(1)*/

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        
        sort(a.begin(), a.begin()+n);
        
        long long minDiff = INT_MAX;
        for(int idx=0; idx<n-m+1; ++idx){
            if(a[idx+m-1]-a[idx]<minDiff){
                minDiff = a[idx+m-1]-a[idx];
            }
        }
        return minDiff;
    }   
};

