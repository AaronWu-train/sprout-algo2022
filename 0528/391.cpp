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


signed main() {_
    int t;
    cin >> t;
    while (t--) {
        int n,m,s,e,f;
        cin >> n >> m >> s >> e >> f;
        vector<pair<ll, ll>>adj[105];
        for (int i = 0; i < m; ++i) {
            ll a,b,c,d,cp;
            cin >> a >> b >> c >> d >> cp;
            ll w;
            if(d>=f){
                w = c*f;
            }else{
                w = (d*c)+((f-d)*cp);
            }
            adj[a].push_back({w,b});
        }
        vector<ll>dis(n+5,1e16);
        queue<ll>qe;
        qe.push(s);
        dis[s]=0;
        while (!qe.empty()) {
            auto i = qe.front();
            qe.pop();
            for (auto [w,v] : adj[i]) {
                if (dis[i] + w < dis[v]) {
                    dis[v] = dis[i] + w;
                    qe.push(v);
                }
            }
        }
        cout << dis[e] << endl;
    }
    return 0;
}
