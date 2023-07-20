3. Longest Consecutive Sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;

        for(auto it: nums){
            s.insert(it);
        }   

        int streak = 0;

        for(auto it:nums){
            if(s.find(it-1)==s.end()){
                int num = it;
                int chain = 1;

                while(s.find(num+1)!=s.end()){
                    num = num+1;
                    chain = chain+1;
                }

                streak = max(streak, chain);
            }
        }

        return streak;
    }
};