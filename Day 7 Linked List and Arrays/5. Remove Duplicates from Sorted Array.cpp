5. Remove Duplicates from Sorted Array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // set<int> s;
        // for(int i=0;i<nums.size();i++){
        //     s.insert(nums[i]);
        // }
        // int i=0;
        // int k=s.size();
        // for(auto it=s.begin();it!=s.end();it++){
        //     cout<< *it << " ";
        // }
        // cout<<endl;
        // for(auto it=s.begin();it!=s.end();it++){
        //     nums[i]=*it;
        //     i++;
        // }

        // return k;

        int f  = 0;
        int s;

        for(s = 1; s<nums.size(); s++){
            if(nums[s]!=nums[f]){
                f++;
                nums[f] = nums[s];
            }
        }

        return (f+1);
    }
};