#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define AI(x) begin(X),end(x)
#define endl '\n'
#ifdef DEBUG
#define debug(args...) LKJ("[ "+string(#args)+" ]", args)
template<class I> void LKJ(I&&x){ cerr << x << "\n";}
template<class I, class...T> void LKJ(I&&x, T...t){cerr << x << ", "; LKJ(t...);}
template<class I> void OI(I a, I b){ while(a < b) cerr << *a << " \n"[next(a) == b], ++a; }
#else
#define debug(...) 0
#define OI(...) 0
#endif
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int maxn = 100005;


signed main(){_
    int t;
    cin >> t;
    while(t--) {
        int n,m;
        cin >> n >> m;
        vector<int>adj[maxn];
        vector<int>ind(n,0);
        for (int i = 0; i < m; ++i) {
            int a,b;
            cin >> a >> b;
            adj[a].push_back(b);
            ind[b]++;
        }
        vector<int>ans;
//        vector<bool>visited(n);
        priority_queue<int,vector<int>,greater<int>>bfs;
        for (int i = 0; i < n; ++i) {
            if (ind[i]==0) {
                bfs.push(i);
            }
        }
        while (!bfs.empty()) {
            auto cur =bfs.top();
            bfs.pop();
//            debug(cur);
//            visited[cur]=1;
            ans.push_back(cur);
            for (auto i : adj[cur]) {
                ind[i]--;
                if (ind[i]==0) {
                    bfs.push(i);
                }
            }
        }
        if(ans.size()<n){
            cout << "QAQ\n";
        }else{
            for (int i = 0; i < n-1; ++i) {
                cout << ans[i] << " ";
            }
            cout << ans[n-1] << endl;
        }
    }
}
