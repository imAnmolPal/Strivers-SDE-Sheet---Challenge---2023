// 1. Search in a 2 D matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0;
        int right = m*n-1;

        while(left<=right){
            int mid = (left+right)/2;
            int i = mid/n;
            int j = mid%n;
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]>target) right = mid-1;
            else left = mid+1;
        }

        return false;
    }
};