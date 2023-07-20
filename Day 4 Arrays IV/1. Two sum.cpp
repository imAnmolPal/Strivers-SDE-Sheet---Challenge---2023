// 1. Two sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;

        for(int i = 0; i<nums.size(); i++){
            int num = nums[i];
            int req = target - num;
            if(mp.find(req)!=mp.end()){
                return {mp[req], i};

            }else{
                mp[nums[i]]= i;
            }
        }

        return {};
    }
};


