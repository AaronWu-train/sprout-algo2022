#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define AI(x) begin(x),end(x)
#define ll long long int
#define endl '\n'
#ifdef DEBUG
#define debug(args...) LKJ("[ "+string(#args)+" ]", args)
template<class I> void LKJ(I&&x){ cerr << x << '\n'; }
template<class I, class...T> void LKJ(I&&x, T&&...t){ cerr << x << ", ", LKJ(t...); }
template<class I> void OI(I a, I b){ while(a < b) cerr << *a << " \n"[next(a) == b], ++a; }
#else
#define debug(...) 0
#define OI(...) 0
#endif
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int MAXN = 1<<16;

ll TSP (int S, int x, int n, vector<vector<ll>>& dp , vector<vector<ll>>&dis) {
    if (dp[x][S]!=-1) {
//        cout << "weewe\n";
        return dp[x][S];
    }
    if (S==(1<<x)) {
        dp[x][S]=dis[x][0];
        return dp[x][S];
    }
    int mask = 1 << x;
    dp[x][S] = 1e9;
    for ( int i = 0; i < n; ++i ) {
        if ( i != x && ( S & ( 1 << i ) ) ){ // i 在status裏面
//            debug(S-mask,i);
            dp[x][S] = min( dp[x][S], TSP(S-mask, i, n,dp,dis) + dis[i][x]);
        }
    }
//    debug(x,S,dp[x][S]);
    return dp[x][S];
}

signed main() {_
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<ll>> dis (n+5,vector<ll>(n+5,0));
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                ll temp;
                cin >> temp;
                dis[i][j] = dis[j][i] = temp;
            }
        }
        vector<vector<ll>> dp(20,vector<ll>(MAXN+5,-1));
        dp[0][0] = 0;
        cout << TSP((1<<n)-1, 0, n, dp, dis) << endl;
        
    }
    return 0;
}

/*
 2
 3
 1 2
 3
 4
 1 3 6
 2 5
 4
 */
