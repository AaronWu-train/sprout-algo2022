#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <bitset>
#include <queue>
#include <stack>
#include <iomanip>
#define All(x) begin(x),end(x)
#define ll long long int
#define endl '\n'
#ifdef DEBUG
#define print(v) cerr<<#v<<": "; for(auto& n: v) cerr << n << " \n"[&n == &v.back()]
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define Report(x) 0
#else
#define print(v) 0
#define debug(x) 0
#endif
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

void mysolve(int n, int add, int daq,int dx,int dy,vector<vector<int>>&v){
    if (n == 1) {
        v[dx][dy] = 1+add+daq;
        return;
    }
    mysolve(n/2, add, daq, dx, dy,v);
    mysolve(n/2, add, daq, dx+n/2, dy+n/2,v);
    mysolve(n/2, add+n-1, 0, dx, dy+n/2,v);
    mysolve(n/2, add+n-1, n-1, dx+n/2, dy,v);
}

void solve(int N){
    vector<vector<int>>v(N,vector<int>(N,0));
    mysolve(N,0,0,0,0,v);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            Report(v[i][j]);
#ifdef DEBUG
            cout << setw(2) << v[i][j] << " ";
#endif
        }
#ifdef DEBUG
        cout << endl;
#endif
    }
}
#ifdef DEBUG
signed main() {_
    solve(8);
    return 0;
}
#endif
