// 4. Find the Duplicate Number

// slow fast approach 


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    	int slow = nums[0];
    	int fast = nums[0];

    	// cant directly use while loop as condition will fail in first iteration itself 
    	do{
    		slow = nums[slow];
    		fast = nums[nums[fast]];
    	}while(slow!=fast);

    	fast = nums[0];
    	while(slow!=fast){
    		slow = nums[slow];
    		fast = nums[fast];
    	}

    	return fast;
    }
};