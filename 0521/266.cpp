#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

signed main() {_
    int n,m;
    string tem;
    cin >> n >> m;
    unordered_map<string, int>ump;
    for (int i = 0; i < n; ++i) {
        cin >> tem;
        ump[tem]++;
    }
    for (int i = 0; i < m; ++i) {
        cin >> tem;
        cout << ump[tem]<<endl;
    }
    return 0;
}
