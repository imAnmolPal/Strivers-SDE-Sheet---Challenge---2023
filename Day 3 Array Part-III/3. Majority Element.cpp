3. Majority Element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // int count = 1;
        // int element = nums[0];

        // for(int i=1;i<nums.size();i++){
        //     if(nums[i]==element){
        //         count++;
        //     }else{
        //         count--;
        //     }
        //     if(count==0){
        //         count=1;
        //         element = nums[i];
        //     }
        // }

        // return element;
        int cnt = 0;
        int element;
        for(auto it : nums){
            if(cnt == 0){
                element = it;
            }
            if(element == it){
                cnt++;
            }else{
                cnt--;
            }
        }

        return element;
    }
};