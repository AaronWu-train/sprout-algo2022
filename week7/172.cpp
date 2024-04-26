#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long int
#define endl '\n'
#define print(v) cerr<<#v<<": "; for(auto& n: v) cerr << n << " \n"[&n == &v.back()]
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const ll mod = 1000007;
ll nCr[105][105];

signed main() {_
    int t;
    cin >> t;
    for (int i = 0 ; i < 105; ++i) {
        nCr[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            nCr[i][j] = (nCr[i-1][j-1]+nCr[i-1][j]) % mod;
        }
    }
    while (t--) {
        int n,m;
        cin >> n >> m;
        vector<ll>arr(n);
        for (auto &i : arr)cin >> i;
        vector<ll>dp(m+5,0);
        for (int i = 1; i <= m; ++i) {
            ll temp = 1;
            for (int j = 0; j < n; j++) {
                temp = (1ll*nCr[i][arr[j]]*temp)%mod;
            }
            dp[i] = temp%mod;
            for (int j=1 ; j <= i-1;j++) {
                dp[i]-=((1LL*dp[i-j]*nCr[i][j])%mod);
            }
            dp[i] = (dp[i]%mod+mod)%mod;
        }
        cout << dp[m] << endl;
    }
    return 0;
}
