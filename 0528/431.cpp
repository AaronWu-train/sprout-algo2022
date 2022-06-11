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
//const int maxn = 200005;
const ll INF = 1e15;

signed main() {_
    int n,m,q;
    cin >> n >> m >> q;
    vector<vector<pair<ll, ll>>>adj(n+5);
    vector<vector<pair<ll, ll>>>radj(n+5);
    for (int i = 0; i < m; ++i) {
        ll a,b,w;
        cin >> a >> b >> w;
        adj[a].push_back({w,b});
        radj[b].push_back({w,a});
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>pq;
    vector<ll>dis(n+5,INF);
    dis[1]=0;
    pq.push({0,1});
    vector<bool>visited(n+5);
    while (!pq.empty()) {
        auto [w,v] = pq.top();
        pq.pop();
        if (visited[v]) continue;
        visited[v]=1;
        for (auto [w_2,v_2] : adj[v]) {
            if (w+w_2 < dis[v_2]) {
                dis[v_2] = w+w_2;
                pq.push({dis[v_2],v_2});
            }
        }
    }
    vector<ll>rdis(n+5,INF);
    rdis[n]=0;
    pq.push({0,n});
    vector<bool>rvisited(n+5);
    while (!pq.empty()) {
        auto [w,v] = pq.top();
        pq.pop();
        if (rvisited[v]) continue;
        rvisited[v]=1;
        for (auto [w_2,v_2] : radj[v]) {
            if (w+w_2 < rdis[v_2]) {
                rdis[v_2] = w+w_2;
                pq.push({rdis[v_2],v_2});
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        int c,d;
        cin >> c >> d;
        cout << min(dis[n], dis[c]+rdis[d]+1) << endl;
    }
    
    
    
    return 0;
}
