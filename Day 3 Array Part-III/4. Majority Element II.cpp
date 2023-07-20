// 4. Majority Element II

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    	int num1 = -100000007;
    	int num2 = -100000007;

    	int c1= 0;
    	int c2= 0;

    	for(auto it: nums){
    		if(it==num1){
    			c1++;
    		} 
    		else if(it==num2){
    			c2++;
    		}
    		else if(c1==0){
    			num1 = it;
    			c1=1;
    		}
    		else if(c2==0){
    			num2 = it;
    			c2 = 1;
    		}
    		else{
    			c1--;
    			c2--;
    		}
    	}

    	int sz = floor((nums.size())/3);
    	c1 = 0;
    	c2 = 0;

    	for(auto it: nums){
    		if(it==num1) c1++;
    		if(it==num2) c2++;
    	}
    	vector<int> ans;
    	if(c1>sz) ans.push_back(num1);

    	if(c2>sz) ans.push_back(num2);

    	return ans;

    }
};