#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

struct node{
    vector<int>child;
    int boxes = 1;
    bool visited = 0;
};

vector<node>arr;

int dfs(int i){
    auto& cur = arr[i];
    if (cur.visited) {
        return cur.boxes;
    }else{
        cur.visited = 1;
        if (cur.child.empty()) {
            return 1;
        }
        for (auto& i : cur.child) {
            cur.boxes += dfs(i);
        }
        return cur.boxes;
    }
}

int main() {_
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        arr.clear();
        arr.resize(n+5);
        for (int i = 0; i < m; ++i) {
            int x,y;
            cin >> x >> y;
            arr[x].child.push_back(y);
        }
        int q;
        cin >> q;
        for (int i = 0; i < q; ++i) {
            int tem;
            cin >> tem;
            cout << dfs(tem) << '\n';
        }
    }
    return 0;
}
