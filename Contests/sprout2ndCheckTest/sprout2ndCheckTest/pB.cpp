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
const int MAXN = (int)1e6+5;
int n,m;
struct DSU{
    ll dsu[MAXN] = {0};
    void Init(){
        for (int i=0;i<=n;i++) dsu[i] = i;
    }
    ll query(ll k){
        if (k==dsu[k]) return k;
        dsu[k] = query(dsu[k]);
        return dsu[k];
    }
    void modify (ll x,ll y){
        ll xA = query(x);
        ll yA = query(y);
        if (xA!=yA) dsu[xA] = yA;
    }
};
vector<pair<ll, pair<ll, ll>>> arr;

ll check(ll x) {
    DSU ddd;
    ddd.Init();
    ll ans = 0;
    for (ll i = x; i < m; ++i) {
        if ( ddd.query(arr[i].second.first) != ddd.query(arr[i].second.second) ) {
            ddd.modify(arr[i].second.first, arr[i].second.second);
            ans += arr[i].first;
        }
    }
    auto j = ddd.query(n);
    for (int i = 1; i<n; ++i) {
        if (ddd.query(i) != j) return -1;
    }
    return ans;
}

signed main() {_
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        ll u,v,w;
        cin >> u >> v >> w;
        arr.push_back({w,{u,v}});
    }
    sort(arr.begin(),arr.end());
    ll l = 0;
    ll r = m;
    while (r - l > 1) {
        ll mid = l + (r-l)/2;
        ll k = check(mid);
//        debug(l,r,mid,k);
        if (k == -1) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    ll temp = check(r);
    if (temp!=-1) cout << temp << endl;
    else cout << check(l) << endl;
    return 0;
}
