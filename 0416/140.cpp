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

const int mod = 1000007;

signed main() {_
    int t;
    cin >> t;
    vector<int> asks(t);
    int maxn = 0;
    for (auto &k : asks){
        cin >> k;
        maxn = max(k, maxn);
    }
    vector<vector<vector<ll>>>dp(maxn+5, vector<vector<ll>>(3,vector<ll>(3,0)));
    dp[1][0][0] = dp[1][1][1] = dp[1][2][2] = 1;
    for (int i = 2; i <= maxn; ++i) {
        for (int j = 0 ; j < 3; ++j) {
            dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1] + dp[i-1][j][2])%mod;
            dp[i][j][1] = (dp[i-1][j][0] + dp[i-1][j][1])%mod;
            dp[i][j][2] = (dp[i-1][j][0] + dp[i-1][j][2])%mod;
        }
    }
    
    for (auto &k : asks){
        cout << (dp[k][0][0]+dp[k][0][1]+dp[k][0][2]
                +dp[k][1][0]+dp[k][1][1]
                +dp[k][2][0]+dp[k][2][2])%mod << endl;
    }
    
    return 0;
}
