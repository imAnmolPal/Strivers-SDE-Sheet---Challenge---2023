// 6.Best Time to BUY and SELL STOCK


//  brute force approach would be to try all possible 
// buying and selling options 

// optimized approach would be to solve it in 
// big oh of N by keeping track of minprice and maxProfit
int maximumProfit(vector<int> &prices){
	int minPrice = INT_MAX;
	int maxPro = 0;

	for(int i=0;i<prices.size();i++){
		minPrice = min(minPrice, prices[i]);
		maxPro = max(maxPro, prices[i]-minPrice);
	}

	return maxPro;

}