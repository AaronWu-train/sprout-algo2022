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

typedef pair<ll, ll> pt;
#define X first
#define Y second
pt point(ll a, ll b){return make_pair(a, b);}
pt operator + (const pt& a, const pt& b){
    return pt(a.X + b.X, a.Y+b.Y);
}
pt operator - (const pt& a, const pt& b){
    return pt(a.X - b.X, a.Y - b.Y);
}
ll operator * (const pt& a, const pt& b){
    return a.X*b.X + a.Y*b.Y;
}
ll operator ^ (const pt&a, const pt&b) {
    return a.X*b.Y - a.Y*b.X;
}
ll abs(pt a) {
    return a.X*a.X + a.Y*a.Y;
}

signed main() {_
    ll n;
    cin >> n;
    vector<pt>arr;
    for (ll i = 0; i < n; ++i) {
        pt temp;
        cin >> temp.X >> temp.Y;
        arr.push_back(temp);
    }
    map<ll,ll>mp;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            mp [abs( arr[i] - arr[j] )]++;
        }
    }
    ll ans = 0;
    for (auto [v,w] : mp) {
        ans += w*(w-1)/2;
    }
    cout << ans << endl;
    return 0;
}
