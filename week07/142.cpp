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
        int n,k;
        cin >> n >> k;
        vector<ll>arr(n);
        for (ll &i : arr)cin >> i;
        vector<ll>dp(n);
        dp[0] = max(0ll,arr[0]);
        for (int i = 1; i < k; ++i) {
            dp[i] = max(dp[i-1],arr[i]);
        }
        for (int i = k; i < n; ++i) {
            dp[i] = max(dp[i-1],dp[i-k]+arr[i]);
        }
        cout << dp[n-1] << endl;
        
//        vector<ll>dp[2];
//        dp[0].resize(n,0);
//        dp[1].resize(n,0);
//
//        if (n==1) {
//            cout << arr[0] << endl;
//            break;
//        }
//        dp[1][0] = arr[0];
//        for (int i = 1; i < n; ++i) {
//            if (i-k>=0) {
//                dp[1][i] = max(dp[0][i-k],dp[1][i-k])+arr[i];
//            }else{
//                dp[1][i] = arr[i];
//            }
//            dp[0][i] = max(dp[0][i-1], dp[1][i-1]);
//        }
//        cout << max(dp[0][n-1],dp[1][n-1]) << endl;
//    }
//    
    return 0;
}
