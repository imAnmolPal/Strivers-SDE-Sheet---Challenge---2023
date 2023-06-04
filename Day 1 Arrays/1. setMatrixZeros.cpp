// set matrix zero

// Soln with O(n) space

void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
	int n = matrix.size();
	int m = matrix[0].size();

	int col[m] = {0};
	int row[n] = {0};

	for(int i=0;i<n;i++){
		for(int j=0; j<m;j++){
			if(matrix[i][j]==0){
				row[i] = 1;
				col[j] = 1;
			}
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0; j<m;j++){
			if(row[i]==1 or col[j]==1){
				matrix[i][j] = 0;
			}
		}
	}
}

// optimized solution 

void setZeros(vector<vector<int>> &matrix)
{
	// we will make use of 0th row and 0th col 
	int n = matrix.size();
	int m = matrix[0].size();
	int col0 = 1;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(matrix[i][j]==0){
				matrix[i][0] = 0;
				if(j!=0) matrix[0][j] = 0;
				else col0 = 0;
			}
		}
	}

	for(int i = 1; i<n; i++){
		for(int j=1; j<m; j++){
			if(matrix[i][0]==0 or matrix[0][j]==0){
				matrix[i][j] = 0;
			}
		}
	}

	if(matrix[0][0]==0){
		for(int i=0;i<m;i++){
			matrix[0][i] = 0;
		}
	}

	for(col0 == 0){
		for(int i=0;i<n;i++){
			matrix[i][0] = 0;
		}
	}
}