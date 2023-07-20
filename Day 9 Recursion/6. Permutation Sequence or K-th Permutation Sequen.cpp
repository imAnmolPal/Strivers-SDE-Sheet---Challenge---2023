// 6. Permutation Sequence or K-th Permutation Sequence

// Bruteforce ......... optimized bruteforce 

class Solution {
public:

    vector<int> nextPermutation(vector<int> &nums, int n)
	{
        //  Write your code here.
        int k,l;
        if(n==1) return nums;
        // a[i] < a[i+1] -> idx 1
        for(k = n-2; k>=0;k--){
            if(nums[k]<nums[k+1]){
                break;
            }
        }

        if(k<0){
            reverse(nums.begin(), nums.end());
            return nums;
        }else{
            // a[idx 2] > a[idx 1]
            for(l=n-1;l>k;l--){
                if(nums[l]>nums[k]){
                    break;
                }
            }
        }

        // swap a[idx 1] and a[idx 2]
        swap(nums[k], nums[l]);

        // reverse a[idx1 + 1] and a[last]
        reverse(nums.begin()+k+1, nums.end());

        return nums;
    }
    string getPermutation(int n, int k) {
        vector<int> nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }   

        while(--k){
            nums = nextPermutation(nums, nums.size());
        }
    
        string s;
        // for(auto it: nums){
        //     cout<<it;
        // }
        cout<<endl;
        for(int i=0;i<nums.size();i++){
            char c = 48+(nums[i]);
            cout<<c;
            s+=c;
        }

        return s;
    }
};



//  Optimized Approach 


