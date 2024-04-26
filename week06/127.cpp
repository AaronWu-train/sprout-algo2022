#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <bitset>
#define All(x) begin(x),end(x)
#define ll long long int
#define endl '\n'
#ifdef DEBUG
#define print(v) cerr<<#v<<": "; for(auto& n: v) cerr << n << " \n"[&n == &v.back()]
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#else
#define print(v) 0
#define debug(x) 0
#endif
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
#ifdef DEBUG
ll mat[1000][1000];
int then,them;
void Report(int val){
    cout << val << endl;
}
ll GetVal(int p, int q){
    return mat[p][q];
}
#endif

vector<int>ans;

void mysolve(int up, int down, int left, int right){
    if (down < up) {
        return;
    }
    int mid = (up + down) / 2;
    int pos = 0;
    ll maxn = LLONG_MIN;
    for (int i = left; i <= right; ++i) {
        ll check = GetVal(mid, i);
        if (check > maxn) {
            pos = i;
            maxn = check;
        }
    }
    ans[mid] = pos;
    if (up == down) {
        return;
    }
    mysolve(up, mid-1, left, pos-1);
    mysolve(mid+1, down, pos+1, right);
    return;
}

void solve(int N,int M){
//    cerr << "WEQW" << endl;
    ans.resize(N+5);
    mysolve(1, N, 1, M);
    for (int i = 1; i <= N; ++i) {
        Report(ans[i]);
    }
}

#ifdef DEBUG
signed main() {_
    cin >> then >> them;
    for (int i = 1; i <= then; ++i) {
        for (int j = 1; j <= them; ++j) {
            cin >> mat[i][j];
        }
//        cerr << "EWQEQE" << endl;
    }
    solve(then, them);
    return 0;
}
#endif
