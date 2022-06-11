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
#define _ ios::sync_with_stdio(false);cin.tie(0);

const double eps = 1e-10;
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
    return a*a;
}
int sign(ll a){
    if (abs(a) < eps) return 0;
    return a > 0 ? 1: -1;
}
int ori (const pt& o, const pt& a, const pt& b) {
    return sign((a-o)^(b-o));
}

signed main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int n;
        scanf("%d",&n);
        vector<pt>arr(n);
        for (auto &i : arr) {
            scanf("%lld %lld", &i.X, &i.Y);
        }
        sort(arr.begin(), arr.end());
        vector<pt> stk(1,arr[0]);
        for (int i = 1; i < n; ++i) {
            while (stk.size() > 1 && ori(stk[stk.size()-2], stk.back(), arr[i]) <= 0 ) {
                stk.pop_back();
            }
            stk.push_back(arr[i]);
        }
        ll r = stk.size();
        for (int i = n-2; i >= 0; --i) {
            while (stk.size() > r && ori(stk[stk.size()-2], stk.back(), arr[i]) <= 0) {
                stk.pop_back();
            }
            stk.push_back(arr[i]);
        }
//        for (auto i : stk) {
//            printf("{%lld,%lld}",i.first,i.second);
//        }
        ll ans = 0;
        for (int i = 0; i < stk.size()-1; ++i) {
            ans += stk[i]^stk[i+1];
        }
        printf("%lld",ans/2);
        if(ans%2){
            printf(".5\n");
        }else{
            printf(".0\n");
        }
                
    }
    return 0;
}
