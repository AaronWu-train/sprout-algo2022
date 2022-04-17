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

signed main() {_
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll>arr(n);
        for (ll &i : arr)cin >> i;
        vector<ll>dp(n);
        dp[0] = max(arr[0],0ll);
        dp[1] = max(dp[0],arr[1]);
        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i-2]+arr[i],dp[i-1]);
        }
        cout << dp[n-1] << endl;
//        vector<ll>dp[2];
//        dp[0].resize(n,0);
//        dp[1].resize(n+5,0);
//        if (n==1) {
//            cout << arr[0] << endl;
//            break;
//        }
//        dp[1][0] = max(arr[0],0ll);
//
//        dp[0][0] = 0;
//
//        for (int i = 1; i < n; ++i) {
//            dp[1][i] = dp[0][i-1] + arr[i];
//            dp[0][i] = max(dp[0][i-1], dp[1][i-1]);
//        }
//
//        cout << max(dp[0][n-1],dp[1][n-1]) << endl;
    }
    
    return 0;
}
