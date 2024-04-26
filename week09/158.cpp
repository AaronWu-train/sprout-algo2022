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
        int n,m,Kmax;
        cin >> n >> m >> Kmax;
        ll v[105] = {0};
        ll w[105] = {0};
        ll dp[2][1005][105] = {0};
        for (int i = 0; i < n; ++i) {
            cin >> w[i] >> v[i];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= m; j++) {
                dp[i%2][j][0] = 0;
                for (int k = 1; k <= Kmax; k++) {
                    if (j < w[i]) {
                        dp[i%2][j][k] = dp[(i+1)%2][j][k];
                    }else{
                        dp[i%2][j][k] = max(dp[(i+1)%2][j][k], dp[(i+1)%2][j-w[i]][k-1]+v[i]);
                    }
                }
            }
        }
        cout << dp[(n-1)%2][m][Kmax] << endl;
    }
    
    
    
    
    return 0;
}
/*
 2
 3 6 3
 2 4
 3 5
 4 6
 3 9 2
 2 4
 3 5
 4 6
 
 */
