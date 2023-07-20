// 3. Combination sum-1

class Solution {
public:

    void f(int ind, int sum, int target, vector<int>& candidates, vector<vector<int>> &ans, vector<int> &ds){
        if(sum==target){
            ans.push_back(ds);
            return;
        }
        if(sum>target) return;
        if(ind<0) return;
        // if()

        // pick
        ds.push_back(candidates[ind]);
        f(ind, sum+candidates[ind], target, candidates, ans, ds);
        ds.pop_back();
        // notPick

        f(ind-1, sum, target, candidates, ans, ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;

        f(candidates.size()-1, 0, target, candidates, ans, ds);
        return ans;
    }
};