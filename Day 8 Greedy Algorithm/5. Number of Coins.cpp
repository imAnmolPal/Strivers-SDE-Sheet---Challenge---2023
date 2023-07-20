// 5. Number of Coins

class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    
		int count = 0;
	    for(int i=M-1; i>=0;i--){
	    	while(V>=coins[i]){
	    		V-=coins[i];
	    		count++;
	    	}
	    }

	    return count;
	} 
	  
};


// version where you have to return list of coins used 

vector<int> MinimumCoins(int n)
{
    // Write your code here
    int coins[]={1,2,5,10,20,50,100,500,1000};

    int num = 9;
    // int cnt = 0;
    vector<int> cnt;
    for(int i=num-1;i>=0;i--){
        while(coins[i]<=n){
            // cnt+=(n/coins[i]);
            cnt.push_back(coins[i]);
            n = n-coins[i];
        }
    }

    return cnt;
}