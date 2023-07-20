1. Subset Sums

// generating all the subsets

class Solution {
public:

    void f(int n, vector<int> &nums, vector<vector<int>> &ds, vector<int> &v){

        if(n==-1){
            ds.push_back(v);
            return;
        }
        // not pick 
        f(n-1, nums, ds, v);

        //  pick
        v.push_back(nums[n]);
        f(n-1, nums, ds, v); 
        v.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ds;
        vector<int> v;
        int n = nums.size();
        f(n-1, nums, ds, v);
        return ds;
    }
};


// Count Number of Maximum Bitwise-OR Subsets
// Find Array Given Subset Sums
// Letter Case Permutation
// Subsets II


// Taking sum

#include <bits/stdc++.h> 

void func(int ind, int sum, vector<int> &arr, int N, vector<int> &sumSubset){
	if(ind == N){
		sumSubset.push_back(sum);
		return;
	}

	// pic the element 
	func(ind+1, sum+arr[ind], arr, N, sumSubset);

	// not pic 
	func(ind+1, sum, arr, N, sumSubset);
}

vector<int> subsetSum(vector<int> &arr)
{
    // Write your code here.
    int N = arr.size();
    vector<int> sumSubset;
	func(0,0, arr, N, sumSubset);
	sort(sumSubset.begin(), sumSubset.end());
	return sumSubset;
}