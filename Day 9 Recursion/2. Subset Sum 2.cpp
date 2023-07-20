2. Subset Sum 2

#include <bits/stdc++.h> 

void f(int ind, vector<int> &ds, vector<vector<int>> &ans, vector<int> &arr){
    ans.push_back(ds);
    for(int i=ind;i<arr.size();i++){
        if(i!=ind and arr[i]==arr[i-1]) continue;
        ds.push_back(arr[i]);
        f(i+1, ds, ans, arr);
        ds.pop_back();
    }
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.'

    vector<vector<int>> ans;
    vector<int> ds;
    sort(arr.begin(),arr.end());
    f(0, ds, ans, arr);
    return ans;
}