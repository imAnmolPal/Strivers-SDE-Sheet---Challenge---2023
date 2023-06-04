// 4. Maximum Subarray Sum

// Brute force will be to try all subarrays 
// which can be done in O(n x n x n) time complexity

// Now to optimize it further, we will use Kadane's algorithm.

long long maxSubarraySum(int arr[], int n)
{
	long long sum = 0;
	int maxi = INT_MIN;

	for(int i=0;i<n;i++){
		sum+=arr[i];
		maxi = max(maxi, sum);
		if(sum<0) sum = 0;
	} 

	return maxi;
}