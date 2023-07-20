// 4. Largest Subarray with K sum

#include <bits/stdc++.h> 

int getLongestSubarray(vector<int>& arr, int k){
    // Write your code here
      int n = arr.size();
  map<long long, int> mp;

//   int k = 0;

  long long prefixSum = 0;

  int len = 0;
  for(int i=0;i<n;i++){
    prefixSum+=arr[i];
    if(prefixSum==k){
      len = max(len, i-(-1));
    //   mp[prefixSum] = i;
      
    }
    if(mp.find(prefixSum-k)!=mp.end()){
        len = max(len, i-mp[prefixSum-k]); 
    }
    if( mp.find(prefixSum) == mp.end()  )
    {
        mp[prefixSum] = i;
    }
  }

  return len;
}


// Optimized Version 

//  Two Pointer Approach 


int longestSubArrayWithSumK(vector<int> a, long long k){

	int left = 0, right = 0;
	long long sum = a[0];

	int n = a.size();
	int maxLen = 0;

	while(right<n){
		while(left<=right and sum>k){
			sum-= a[left];
			left++;
		}

		if(sum==k){
			maxLen = max(maxLen, right - left + 1);
		}
		right++;
		if(right<n) sum+=a[right];
	}

	return maxLen;
}





































