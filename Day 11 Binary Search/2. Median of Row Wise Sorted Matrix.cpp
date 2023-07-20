// 2. Median of Row Wise Sorted Matrix

// Brute force

/*
	Store each element of the matrix in some array, sort it.
	Return the middle element of the array.
*/


// Optimized Approach - Binary Search

/* We can see how here the search space is monotonous in nature*/


int countSmallerThanMid(vector<int> &row, int mid){
	int l=0, h= row.size()-1;

	while(l<=h){
		int md = (l+h)>>1;
		if(row[md]<=mid){
			l = md+1;
		}else{
			h = md - 1;
		}
	}

	return l;
}

int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.

    // assign the search space 

    int low = 1;
    int high = 1e5;

    // size of matrix 
    int n = matrix.size();
    int m = matrix[0].size();

    while(low<=high){
    	int mid = (low+high)>>1;
    	int count = 0;

    	for(int i=0;i<n;i++){
    		count+= countSmallerThanMid(matrix[i], mid);
    	}

    	if(count<=(n*m)/2) low = mid+1;
    	else high = mid - 1;
    }

    return low;

}