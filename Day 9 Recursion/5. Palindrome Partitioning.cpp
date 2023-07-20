// 5. Palindrome Partitioning

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;

        vector<string> path;

        f(0, path, ans, s);

        return ans;
    }

    void f(int ind, vector<string> &path, vector<vector<string>> &ans, string s){
        if(ind==s.size()){
            ans.push_back(path);
            return;
        }

        for(int i=ind; i<s.size(); i++){
            if(isPalindrome(s, ind, i)){
                string r = s.substr(ind, i-ind+1);
                path.push_back(r);
                f(i+1, path, ans, s);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }

        return true;
    }
};