// 5. Subarrays with XOR K

#include <bits/stdc++.h>

int subarraysWithSumK(vector < int > a, int b) {
    // Write your code here

    map<int, int> mp;

    mp[0] = 1;

    int XR = 0;
    int k = b;
    int cnt = 0;
    for(int i =0 ; i<a.size(); i++){
        XR = XR^a[i];
        int x = XR^k;
        if(mp.find(x)!=mp.end()){
            cnt+=mp[x];
        }
        if(mp.find(XR)!=mp.end()) mp[XR]++;
        else mp[XR] = 1;
    }

    return cnt;
}