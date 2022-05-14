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
template<class I> void OI(I a, I b){while(a < b) cerr << *a << " \n"[next(a) == b],++a;}
template<class I> void OIP(I a, I b){while(a < b) cerr << a->first<< " "<< a->second << endl,++a;cerr<<endl;}
#else
#define debug(...) 0
#define OI(...) 0
#define OIP(...) 0
#endif
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

signed main() {_
    int t;
    cin >> t;
    while (t--) {
        int n,k,c;
        cin >> n >> k >> c;
        vector<ll>val(n);
        for (auto &i : val) cin >> i;
        deque<pair<ll, int>>sindp;
        vector<ll>dp(n,0);
        
        for (int i = 0; i < n; i++) {
            debug(i);
            OIP(AI(sindp));
            while (!sindp.empty() && sindp.front().second < i-k) {
                sindp.pop_front();
            }
            if (sindp.empty()) dp[i] = val[i];
            else dp[i] = val[i] + max(sindp.front().first - c*i,0ll);
            
            while (!sindp.empty() && sindp.back().first < dp[i]+c*i) {
                sindp.pop_back();
            }
            sindp.push_back(make_pair(dp[i]+c*i, i));
        }
        
        ll maxn = INT_MIN;
        for (auto j : dp) {
            maxn = max(maxn,j);
        }
        OI(AI(dp));
        cout << maxn << endl;
        
        
    }
    return 0;
}

/*
 2
 4 2 1
 -1 3 -2 4
 4 2 2
 -1 3 -2 4
 
 
 */

