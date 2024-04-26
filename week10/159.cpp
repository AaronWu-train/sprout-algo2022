#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define AI(x) begin(x),end(x)
#define ll long long int
#define endl '\n'
//#ifdef DEBUG
//#define debug(args...) LKJ("[ "+string(#args)+" ]", args)
//template<class I> void LKJ(I&&x){ cerr << x << '\n'; }
//template<class I, class...T> void LKJ(I&&x, T&&...t){ cerr << x << ", ", LKJ(t...); }
//template<class I> void OI(I a, I b){ while(a < b) cerr << *a << " \n"[next(a) == b], ++a; }
//#else
//#define debug(...) 0
//#define OI(...) 0
//#endif
//#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

//const int MAXN = 100;
const int MAXM = 20000;
string ans[] = {"No\n","Yes\n"};

signed main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;
        vector<int>c(n+5);
        vector<int>k(n+5);
        for ( int i = 1; i <= n; ++i ) {
            cin >> c[i] >> k[i];
        }
        bool dp[2][MAXM+5] = {0};
        dp[0][0] = 1;
        deque<int>tem[200];
        for (int i = 1; i <= n; ++i) {
            for (auto &i : tem) i.clear();
            for (int j = 0; j <= m; ++j) {
                int r = j%c[i];
                if (dp[(i+1)%2][j]) {
                    dp[i%2][j] = dp[(i+1)%2][j];
                    tem[r].push_back(j);
                }
                else {
                    if (c[i] > j)continue;
                    int f=j-k[i]*c[i];
                    while (!tem[r].empty() && tem[r].front()<f) {
                        tem[r].pop_front();
                    }
                    dp[i%2][j] = !tem[r].empty();
                }
            }
        }
        cout << ans[dp[n%2][m]];
    }
    return 0;
}

/*

 2
 2 11
 2 2
 3 3
 2 11
 2 3
 3 2

 */
