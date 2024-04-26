#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define AI(x) begin(x),end(x)
#define int long long
#define ll long long
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
    ll n,k;
    cin >> n >> k;
    vector<ll>SUM(n+5, 0);
    vector<ll>arr(n+5, 0);
    vector<ll>dp(n+5, 0);
    for (ll i = 0; i < n; ++i) {
        cin >> arr[i];
        if (i == 0)SUM[i]=arr[i];
        else SUM[i] = SUM[i-1] + arr[i];
    }

    deque<ll>mono;
    mono.push_back(n-1);
    dp[n-1]=0;
    for (ll i = n-2; i>=0; --i) {
        while (!mono.empty() && mono.front() > i+k) mono.pop_front();
        dp[i] = dp[mono.front()]+SUM[n-1]-SUM[mono.front()-1];
        if (i+k >= n)dp[i] = max(dp[i],0ll);
        while (!mono.empty() && dp[mono.back()]-SUM[mono.back()-1] <= dp[i]-SUM[i-1]) {
            mono.pop_back();
        }
        mono.push_back(i);
    }
    cout << dp[0] << endl;
    return 0;
}
