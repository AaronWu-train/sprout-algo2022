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


signed main() {_
    int n;
    cin >> n;
    vector<pt>arr;
    for(int i = 0; i < n; ++i){
        pt a;
        cin >> a.X >> a.Y;
        arr.push_back(a);
    }
    ll left = 0;
    ll bck  = 0;
    ll right= 0;
    for (int i = 0; i < n-2; ++i) {
        if (sign( (arr[i+1] - arr[i]) ^ (arr[i+2] - arr[i+1]) ) > 0) {
            left++;
        }
        else if (sign( (arr[i+1] - arr[i]) ^ (arr[i+2] - arr[i+1])) < 0 ) {
            right++;
        }
        else {
            if ( sign( (arr[i+1] - arr[i]) * (arr[i+2] - arr[i+1])) <0 ) {
                bck++;
            }
        }
    }
    cout << left<< " " << right << " "<< bck << endl;
    return 0;
}
