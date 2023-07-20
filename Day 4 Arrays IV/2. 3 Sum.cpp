// 2. 3 Sum

// Approach 1 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> s;

        for(int i=0;i<nums.size(); i++){
            map<int, int> mp;
            for(int j=i+1;j<nums.size(); j++){
                if(mp.find(-(nums[i]+nums[j]))!= mp.end()){
                    vector<int> temp={{nums[i], nums[j], -(nums[i]+nums[j])}};
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                }
                mp[nums[j]]=j;
            }
        }

        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};


// Approach 2 (More optimized) 

// two pointer approach 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> s;

        sort(nums.begin(), nums.end());

        for(int i=0;i<nums.size(); i++){
            int left = i+1, right=nums.size()-1;
            while(left<right){
                if(nums[i] + nums[left] + nums[right] == 0){
                    // 
                    vector<int> temp = {nums[i], nums[left], nums[right]};
                    s.insert(temp);
                    left++;
                    right--;
                }

                else if(nums[i] + nums[left] + nums[right] < 0){
                    left++;
                }else{
                    right--;
                }
            }
        }

        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};