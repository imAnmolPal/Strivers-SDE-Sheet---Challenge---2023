// 3. Maximum Sum Combination

vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.

	// priority_queue<int, vector<int>, greater<int>> minH;
	priority_queue<int> maxH;
	for(int i=0;i<n;i++){
		for(int j =0; j<n;j++){
			maxH.push(a[i]+b[j]);

			// if(minH.size()>k) minH.pop();
		}
	}

	vector<int> ans;
	while(k--){
		ans.push_back(maxH.top());
		maxH.pop();
	}

	// sort(ans.begin(), ans.end(), greater<int>());

	return ans;
}