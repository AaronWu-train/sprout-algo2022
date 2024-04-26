#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <bitset>
#define All(x) begin(x),end(x)
#define ll long long int
#define endl '\n'
#define print(v) cerr<<#v<<": "; for(auto& n: v) cerr << n << " \n"[&n == &v.back()]
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;


ll rangeans(int l, int r,vector<vector<ll>>&dp,vector<ll>&arr,vector<ll>&pre) {
    if (dp[l][r] != 0) {
        return dp[l][r];
    }
    if (r==l){
        return 0;
    }
    ll minn = INT_MAX;
    for (int i = l; i < r; ++i) {
        minn = min(minn, rangeans(l,i,dp,arr,pre) + rangeans(i+1,r,dp,arr,pre));
    }
    dp[l][r] = minn + pre[r] - (l?pre[l-1]:0);
    return dp[l][r];
}



signed main() {_
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll>arr(n+5,0);
        vector<ll>pre(n+5,0);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            pre[i] += arr[i];
            pre[i+1] += pre[i];
        }
        vector<vector<ll>>dp(105,vector<ll>(105,0));
        cout << rangeans(0, n-1, dp, arr, pre) << endl;
    }
    return 0;
}
