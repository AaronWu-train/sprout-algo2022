#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <bitset>
#include <queue>
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

void bfs(int start){
    
}

signed main() {_
    int n,m;
    cin >> n >> m;
    vector<int>adj[n+5];
    vector<int>degCount(n+5,0);
    int maxdeg = 0;
    int maxnode = 1;
    
    for (int i = 0; i < m; ++i) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        degCount[a]++;
        degCount[b]++;
        if (degCount[a] > maxdeg) {
            maxdeg = degCount[a];
            maxnode = a;
        }
        if (degCount[b] > maxdeg) {
            maxdeg = degCount[b];
            maxnode = b;
        }
    }
    int q;
    cin >> q;
    vector<int>dis(n+1,0);
    vector<bool>visited(n+1,0);

    queue<int> que;
    que.push(maxnode); //把第一個點push進queue
    visited[maxnode] = true; //已造訪
    while(que.size()){//當還有東西時
        int cur = que.front();
        debug(cur);
        for(auto i:adj[cur]){
            if(!visited[i]){
                visited[i] = true;
                dis[i] = dis[cur]+1;
                que.push(i);
            }
        }
        que.pop();
    }
    for (int i = 0; i < q; i++) {
        int a,b;
        
        cin >> a >> b;
        cout << dis[a] + dis[b] << endl;
    }
    
    return 0;
}
