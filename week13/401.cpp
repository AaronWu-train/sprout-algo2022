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
    if (fabs(a) < eps) return 0;
    return a > 0 ? 1: -1;
}
int ori (const pt& o, const pt& a, const pt& b) {
    return sign((a-o)^(b-o));
}
bool btw (const pt &a, const pt&b, const pt&c) {
    if (ori(a, b, c)!=0) return 0;
    return ((c-a)*(c-b))<=0;
}

bool banana(const pt& p1, const pt& p2, const pt& p3, const pt& p4) {
    int a123 = ori(p1,p2,p3);
    int a124 = ori(p1,p2,p4);
    int a341 = ori(p3,p4,p1);
    int a342 = ori(p3,p4,p2);
    if (a123 == 0 && a124 == 0) {
        return btw(p1, p2, p3) || btw(p1, p2, p4) || btw(p3, p4, p1) || btw(p3, p4, p2);
    }
    return a123*a124 <= 0 && a341*a342 <=0;
}

signed main() {_
    int n;
    cin >>n ;
    while (n--) {
        pt a,b,c,d;
        cin >> a.X >> a.Y >> b.X >> b.Y >> c.X >> c.Y >> d.X >> d.Y;
        if (banana(a, b, c, d)) {
            cout << "Yes\n" ;
        }else{
            cout << "No\n";
        }
    }
}
