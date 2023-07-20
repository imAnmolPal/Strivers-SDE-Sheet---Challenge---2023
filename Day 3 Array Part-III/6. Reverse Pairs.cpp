6. Reverse Pairs 


class Solution {
public:
    int cnt = 0;

    void merge(vector<int>& nums, int low, int mid, int high){
        vector<int> temp;

        int left = low;
        int right = mid+1;

        while(left<=mid and right<=high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }else{
                temp.push_back(nums[right]);
                // cnt+=(mid-left+1);
                right++;
            }
        }

        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }

        while(right<=high){
            temp.push_back(nums[right]);
            right++;
        }

        for(int i=low; i<=high; i++){
            nums[i]=temp[i-low];
        }
    }
    void countReversePair(vector<int>& nums, int low, int mid, int high){
        int left = low;
        int right = mid+1;

        for(left = low; left<=mid;left++){
            while(right<=high and nums[left]>(long long)2*nums[right]){
                right++;
            }
            cnt+=(right-mid-1);
        }
    }
    void mergeSort(vector<int>& nums, int low, int high){
        if(low>=high) return;
        int mid = (low+high)/2;
        mergeSort(nums,low, mid);
        mergeSort(nums, mid+1, high);
        countReversePair(nums, low, mid, high);
        merge(nums, low, mid, high);
    }
    int reversePairs(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;

        mergeSort(nums, low, high);
        return cnt;
    }
};