// 4. Fractional Knapsack

/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:


    static bool comp(Item a, Item b){
    	double r1 = (double)a.value/ (double)a.weight;
    	double r2 = (double)b.value/ (double)b.weight;
    	return r1>r2;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here

        sort(arr, arr+n, comp);

        int curWeight = 0;
        double finalvalue = 0.0;

        for(int i=0;i<n;i++){
        	if(curWeight+arr[i].weight<=W){
        		curWeight+=arr[i].weight;
        		finalvalue+=arr[i].value;
        	}
        	else{
        		int remain = W - curWeight;
        		finalvalue +=(arr[i].value/(double)arr[i].weight)*(double)remain;
        		break;
        	}
        }

        return finalvalue;
    }	
        
};



//  Coding Ninja

#include <bits/stdc++.h> 

bool comp(const pair<int, int> i1, const pair<int ,int> i2){
    double r1 = (double) i1.second/(double)i1.first;
    double r2 = (double) i2.second/(double)i2.first;

    return r1>r2;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.

    sort(items.begin(), items.end(), comp);
    double ans = 0;
    int weight = 0;
    for(int i=0;i<n;i++){
        if(items[i].first+weight <= w){
            weight+=items[i].first;
            ans+= items[i].second;
        }else{
            int rem = w - weight;
            double val = (double)items[i].second/(double)items[i].first;
            weight+=rem;
            val = val*rem;
            ans = ans+val;
            // break;
        }
    }
    return ans;
}