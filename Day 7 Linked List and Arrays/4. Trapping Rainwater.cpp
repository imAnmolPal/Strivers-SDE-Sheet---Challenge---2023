// 4. Trapping Rainwater

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n, 0), right(n,0);
        left[0] = height[0];
        int currMax = left[0];
        for(int i=1;i<n;i++){
            if(height[i]>currMax){
                currMax = height[i];
            }
            left[i] = currMax;
        }

        right[n-1] = height[n-1];
        currMax = right[n-1];
        for(int i=n-2;i>=0;i--){
            if(height[i]>currMax){
                currMax = height[i];
            }
            right[i] = currMax;
        }

        int res = 0;

        for(int i = 0; i<n; i++){
            res+=min(left[i], right[i])-height[i];
        }

        return res;
    }
};


// There is one stacked base solution and another two pointer bassed approach. 


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftmax =0, rightmax = 0;
        int left = 0, right = n-1;
        int res = 0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]<leftmax) res+=(leftmax-height[left]);
                else leftmax = height[left];
                left++;
            }else{
                if(height[right]<rightmax){
                    res+=(rightmax - height[right]);
                }else{
                    rightmax = height[right];
                }
                right--;
            }
        }

        return res;
    }
};