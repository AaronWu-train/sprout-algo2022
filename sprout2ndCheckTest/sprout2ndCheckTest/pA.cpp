#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define AI(x) begin(x),end(x)
#define ll long long int
#define endl '\n'
#ifdef AaW
#define debug(args...) LKJ("[ "+string(#args)+" ]", args)
template<class I> void LKJ(I&&x){ cerr << x << '\n'; }
template<class I, class...T> void LKJ(I&&x, T&&...t){ cerr << x << ", ", LKJ(t...); }
template<class I> void OI(I a, I b){ while(a < b) cerr << *a << " \n"[next(a) == b], ++a; }
#else
#define debug(...) 0
#define OI(...) 0
#endif
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mod = 1e9+7;
ll dp[405][20005] = {0};
ll method[405][20005] = {0};
ll bought[405][20005] = {0};
ll boughtmethod[405][20005] = {0};

signed main() {_
    int n, m, c;
    cin >> n >> m >> c;
    
    
    vector<ll>bbmoney(n+5);
    vector<ll>bbhert(n+5);
    for (int i = 1; i <=n; ++i) {
        cin >> bbmoney[i] >> bbhert[i] ;
    }
    vector<ll>a(m+5);
    vector<ll>b(m+5);
    vector<ll>arhert(m+5);
    for (int i = 1; i <= m; ++i) {
        cin >> a[i] >> b[i] >> arhert[i];
    }
    for (int i=0; i <= c; ++i) {
        method[0][i] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= c; ++j) {
            if (j < bbmoney[i]) {
                dp[i][j] = dp[i-1][j];
                method[i][j] = method[i-1][j];
//                debug(i,j,dp[i][j]);
                continue;
            }
            if ( dp[i-1][j] > dp[i-1][ j-bbmoney[i] ] + bbhert[i]) {
                dp[i][j] = dp[i-1][j];
                method[i][j] = method[i-1][j];
            }
            else if ( dp[i-1][j] < dp[i-1][ j-bbmoney[i] ] + bbhert[i]) {
                dp[i][j] = dp[i-1][ j-bbmoney[i] ] + bbhert[i];
                method[i][j] = method[i-1][j-bbmoney[i]];
            }
            else{
                dp[i][j] = dp[i-1][j];
                method[i][j] =( method[i-1][j] + method[i-1][j-bbmoney[i]]) %mod;
            }
//            debug(i,j,dp[i][j]);
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j<=c; ++j) {
            if (j < b[i]) {
                bought[i+n][j] = 0;
                dp[i+n][j] = dp[i+n-1][j];
                method[i+n][j] = method[i+n-1][j];
                debug(i+n,j,dp[i+n][j],method[i+n][j]);
                continue;
            }
            if ( bought[i+n][ j - b[i] ] == 0 || j < b[i]+a[i]) {
                if (j < b[i]+a[i] || dp[i+n-1][j-b[i]-a[i]] + arhert[i] < dp[i+n-1][j]){
                    // up
                    bought[i+n][j] = 0;
                    dp[i+n][j] = dp[i+n-1][j];
                    method[i+n][j] = method[i+n-1][j];
                    debug(i+n,j,dp[i+n][j],method[i+n][j]);
                    continue;
                }
                else if ( dp[i+n-1][j-b[i]-a[i]] + arhert[i] > dp[i+n-1][j]) {
                    // right a
                    bought[i+n][j] = dp[i+n-1][j-b[i]-a[i]] + arhert[i];
                    dp[i+n][j] = dp[i+n-1][j-b[i]-a[i]] + arhert[i];
                    method[i+n][j] = method[i+n-1][j-b[i]-a[i]];
                    boughtmethod[i+n][j] = method[i+n-1][j-b[i]-a[i]];
                }
                else {
                    // both
                    bought[i+n][j] = dp[i+n-1][j-b[i]-a[i]] + arhert[i];
                    dp[i+n][j] = dp[i+n-1][j-b[i]-a[i]] + arhert[i];
                    method[i+n][j] = method[i+n-1][j] + method[i+n-1][j-b[i]-a[i]];
                    boughtmethod[i+n][j] = method[i+n-1][j-b[i]-a[i]];
                }
            }
            else {
                if ( j < b[i] || (dp[i+n-1][j] >= bought[i+n][j-b[i]]+arhert[i] && dp[i+n-1][j] >= dp[i+n-1][j-b[i]-a[i]]+arhert[i])){
                   // up
                   bought[i+n][j] = 0;
                   dp[i+n][j] = dp[i+n-1][j];
                   method[i+n][j] += method[i+n-1][j];
                    if ( j < b[i]) {
                        debug(i+n,j,dp[i+n][j],method[i+n][j]);
                        continue;}
                }
                if ( bought[i+n][j-b[i]]+arhert[i] >= dp[i+n-1][j] && bought[i+n][j-b[i]]+arhert[i] >= dp[i+n-1][j-b[i]-a[i]] +arhert[i]) {
                   // left
                   bought[i+n][j] = 1;
                   dp[i+n][j] = dp[i+n][j-b[i]]+arhert[i];
                   method[i+n][j] += boughtmethod[i+n][j-b[i]];
                   boughtmethod[i+n][j] += boughtmethod[i+n][j-b[i]];
                }
                if ( dp[i+n-1][j-b[i]-a[i]] +arhert[i]>= bought[i+n][j-b[i]]+arhert[i] && dp[i+n-1][j-b[i]-a[i]] +arhert[i]>= dp[i+n-1][j]) {
                    bought[i+n][j] = 1;
                    dp[i+n][j] = dp[i+n-1][j-b[i]-a[i]]+arhert[i];
                    method[i+n][j] += method[i+n-1][j-b[i]-a[i]];
                    boughtmethod[i+n][j] += method[i+n-1][j-b[i]-a[i]];
                }
                bought[i+n][j] = max( dp[i+n-1][j-b[i]-a[i]]+arhert[i], bought[i+n][j-b[i]]+arhert[i] );
                if ( dp[i+n-1][j-b[i]-a[i]]+arhert[i] > bought[i+n][j-b[i]]+arhert[i]) {
                    boughtmethod[i+n][j] = boughtmethod[i+n-1][j-b[i]-a[i]];
                }else if(dp[i+n-1][j-b[i]-a[i]]+arhert[i] < bought[i+n][j-b[i]]+arhert[i]){
                    boughtmethod[i+n][j] = boughtmethod[i+n][j-b[i]];
                }
                else {
                    boughtmethod[i+n][j] = boughtmethod[i+n][j-b[i]]+boughtmethod[i+n-1][j-b[i]-a[i]];
                }
                
            }
            debug(i+n,j,dp[i+n][j],method[i+n][j]);
            method[i+n][j]%=mod;
            boughtmethod[i+n][j]%=mod;
        }
    }
    cout << dp[n+m][c] << " " << method[n+m][c] << endl;
    return 0;
}
