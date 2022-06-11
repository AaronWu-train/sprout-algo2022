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
const int maxn = 505;
const int INF = 1e9;

signed main() {_
    int n;
    cin >> n;
    vector<vector<ll>>dis(n+5,vector<ll>(n+5,INF));
    
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j) {
            cin >> dis[i][j];
            if (dis[i][j]==-1)dis[i][j]=INF;
        }
    }
    vector<ll>ans;
    for (int k = 0; k < n; ++k) {
        ll cur = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
            }
        }
        for (int i = 0; i <= k; ++i) {
            for (int j = 0; j <= k; ++j) {
                cur = max(cur, dis[i][j]);
            }
        }
        ans.push_back(cur);
    }
    for (int i = 0; i < n-1; ++i) {
        if (ans[i]==INF) cout << -1 << " ";
        else cout << ans[i] << " ";
    }
    if (ans[n-1]==INF) cout << -1 << "\n";
    else cout << ans[n-1] << endl;
    return 0;
}
