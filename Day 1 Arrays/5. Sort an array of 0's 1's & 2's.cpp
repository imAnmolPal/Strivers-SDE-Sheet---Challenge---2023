// 5. Sort an array of 0's 1's & 2's

// We can even sort it simply.

// Optimized approach would allow us solve this in O(n) time


void sort012(int *arr, int n)
{
   int low = 0;
   int mid = 0;
   int high = n-1;

   while(mid<=high){
   	if(arr[mid]==0){
   		swap(arr[low], arr[mid]);
   		low++;
   		mid++;
   	}else if(arr[mid]==1){
   		mid++;
   	}else if(arr[mid]==2){
   		swap(arr[mid], arr[high]);
   		high--;
   	}
   }
}