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
        ll n,m;
        cin >> n >> m;
        vector<ll>weight(n+5);
        vector<ll>value(n+5);
        int Vtotal = 0;
        for (ll i = 0; i < n; ++i) {
            cin >> weight[i] >> value[i];
            Vtotal += value[i];
        }
        vector<ll>dp(Vtotal+5,0);
        dp[0] = 0;
        for (int i = 1; i <= Vtotal; i++) {
            dp[i] = INT_MAX;
        }
        
        for (ll i = 0; i < n; ++i) {
            for (ll j = Vtotal; j >= 0; j--) {
                if (value[i] > j) {
                    continue;
                }
                dp[j] = min(dp[j], dp[j-value[i]]+weight[i]);
            }
        }
        int i = Vtotal;
        while (dp[i] > m) {
            i--;
        }
        cout << i << endl;
    }
    return 0;
}

/*
 
 2
 
 2 5
 2 4
 3 3
 
 2 4
 2 4
 3 3
 
*/
