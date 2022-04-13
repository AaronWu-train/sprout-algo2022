#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <bitset>
#define All(x) begin(x),end(x)
#define ll long long int
#define endl '\n'
#define print(v) cerr<<#v<<": ";for(auto& n: v)cerr<<n.first<<" "<<n.second<<" \n"[&n==&v.back()]
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define x first
#define y second
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

inline ll dis(pair<ll, ll>a,pair<ll, ll>b){
    ll t =(b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y);
    return t;
}

ll fun(ll l, ll r,vector<pair<ll, ll>>&arr) {
    if (r<=l) {
        return LLONG_MAX;
    }
    ll mid = (r+l)/2;
//    ll midline = arr[mid].x;
    ll d = min(fun(mid+1,r,arr), fun(l, mid,arr));
    vector<pair<ll, ll>>nearmid;
    for (ll i = mid; i>=l&& arr[mid].x - arr[i].x <= d; --i) {
        nearmid.push_back(arr[i]);
    }
    for (ll i=mid+1; i<=r && arr[i].x - arr[mid].x <= d; ++i){
        nearmid.push_back(arr[i]);
    }
//    for (int i = l; i <= r; ++i) {
//        if (abs(midline-arr[i].x)<=d) {
//            nearmid.push_back(arr[i]);
//        }
//    }
    sort(All(nearmid), [](auto a, auto b){
        return a.y < b.y;
    });
//    print(nearmid);
    for (ll i = 0; i < nearmid.size(); ++i) {
        for (ll j = i+1; j < min((ll)i+3,(ll)nearmid.size()); ++j) {
            d = min(d, dis(nearmid[i],nearmid[j]));
        }
    }
    return d;
}

signed main() {_
    int n;
    cin >> n;
    vector<pair<ll, ll>> arr(n);
    for (ll i = 0; i < n; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(All(arr));
    if (n==1) {
        cout << 0 <<endl;
    } else {
        auto t =  fun(0,n-1,arr);
        cout << min(t,dis(arr[0], arr[1])) << endl;
    }
    return 0;
}
