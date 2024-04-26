#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <bitset>
#ifdef DEBUG
#   define print(v) cerr<<#v<<": ";for(auto& n:v) cerr<<n<<" \n"[&n == &v.back()]
#   define debug(x) cerr<<#x<<" = "<<(x)<<endl
#else
#   define print(v) 0
#   define debug(x) 0
#endif
#define All(x) begin(x),end(x)
#define ll long long int
#define pii pair<int,int>
#define endl '\n'
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

struct node{
    int pop = 0;
    int maxn = 0;
    int minn = 1e9+7;
    vector<int>adj;
};

pair<int, int>dfs(int cur,vector<node>&tree,vector<bool>&visited) {
    visited[cur] = 1;
    
    tree[cur].maxn = tree[cur].minn = tree[cur].pop;
    
    for (auto i : tree[cur].adj ) {
        if (!visited[i]) {
            auto ret = dfs(i, tree, visited);
            tree[cur].maxn = max(tree[cur].maxn, ret.first);
            tree[cur].minn = min(tree[cur].minn, ret.second);
        }
    }
    return make_pair(tree[cur].maxn , tree[cur].minn);
}

signed main() {_
    int n,q;
    cin >> n >> q;
    vector<node>tree(n+5);
    for (int i = 0; i < n-1; ++i) {
        int a,b;
        cin >> a >> b;
        tree[a].adj.push_back(b);
        tree[b].adj.push_back(a);
    }
    for (int i = 1; i <=n ; ++i) {
        cin >> tree[i].pop;
    }
    vector<bool>visited(n+5,0);
    dfs(1, tree, visited);
    for (int i = 0 ; i < q; ++i) {
        int r;
        cin >> r;
        cout << tree[r].maxn - tree[r].minn << endl;
    }
    
    return 0;
}
