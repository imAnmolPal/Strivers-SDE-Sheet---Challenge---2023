6. Longest Substring Without Repeating Characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> mp;

        int left = 0,right = 0;
        int n = s.length();
        // cout<<n<<endl;
        int ans = 0;
        int len = 0;
        while(right<n){
            if(mp.find(s[right])==mp.end()){
                len = right - left + 1;
                ans = max(ans, len);
                mp.insert(s[right]);
                right++;
            }else{
                while(left<right){
                    if(s[left]!=s[right]){
                        mp.erase(s[left]);
                        left++;
                    }else{
                        mp.erase(s[left]);
                        left++;
                        break;
                    }
                }
            }

            cout<<right<<" "<<len<<endl;
        }

        return ans;
    }
};



// Second approach 


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int left = 0, right = 0;
        int len = 0;
        int ans = 0;
        int n = s.length();
        while(right<n){
            if(mp.find(s[right])==mp.end()){
                len = right - left + 1;
                ans = max(ans, len);
                mp[s[right]] = right;
                right++;
            }else{
                left = max(left, mp[s[right]] + 1);
                len = right - left + 1;
                ans = max(ans, len);
                mp[s[right]]=right;
                right++;
            }
            
        }

        return ans;
    }
};