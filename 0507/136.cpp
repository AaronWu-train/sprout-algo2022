#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <bitset>
#define AI(x) begin(x),end(x)
#define ll long long int
#define endl '\n'
#define print(v) cerr<<#v<<": "; for(auto& n: v) cerr << n << " \n"[&n == &v.back()]
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

#ifdef DEBUG
void Report(int n) {
    cout << n << endl;
}
#endif

vector<ll>mysolve(int N, ll k, ll A[]){
    vector<ll>ret;
//    if (N<=20) {
        ll maxn = 1<<N;
        for (ll i = 1; i < maxn; ++i) {
            ll sum = 0;
            for (ll j = 0; j < N; ++j) {
                if (i&(1<<j)) {
                    sum+=A[j];
                    ret.push_back(j);
                }
            }
            if (sum == k) return ret;
            ret.clear();
        }
//    }
    return ret;
}


void solve(int N, ll k, ll A[]) {
    auto ret = mysolve(N, k, A);
    for (auto& item : ret) Report(item+1);
    Report(-1);
}

#ifdef DEBUG
signed main() {_
    int n,k;
    cin >> n >> k;
    ll A[41];
    for (int i = 0; i<n; ++i) {
        cin>>A[i];
    }
    solve(n, k, A);
    return 0;
}
#endif
