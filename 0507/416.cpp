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
const int mod = 1e9+7;
inline ll madd(ll a, ll b){
    a = a%mod;
    b = b%mod;
    return (((a + b)%mod)+mod)%mod;
}

signed main() {_
    int n,a,b,k;
    cin >> n >> a >> b >> k;
    vector<ll>dp[2];
    dp[0].resize(n+1,0);
    dp[1].resize(n+1,0);
    vector<ll>ans(n+1,0);
    ans[a]=1;
    fill(dp[0].begin()+a, dp[0].end(), 1);
    for (int j = 1; j <= k; j++) {
//        cerr<<"-----------------------------"<< endl;
//        debug(j);
//        cerr << endl;
        for (int i = 1; i <= n; i++) {
            if (i == b) ans[i] = 0;
            else if (i < b) {
                ans[i] = madd(dp[(j+1)%2][(i+b-1)/2],-ans[i]);
            }
            else /* i > b */ {
                ans[i] = madd(dp[(j+1)%2][n], -dp[(j+1)%2][(i+b)/2])-ans[i];
            }
//            debug(i);
//            debug(ans[i]);
            dp[j%2][i] = madd(dp[j%2][i-1],ans[i]);
        }
//        print(dp[j%2]);
    }
    cout << dp[k%2][n]%mod << endl;
    return 0;
}
