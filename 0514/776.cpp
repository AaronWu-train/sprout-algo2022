#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define AI(x) begin(x),end(x)
#define ll long long int
#define endl '\n'
#define print(v) cerr<<#v<<": "; for(auto& n: v) cerr << n << " \n"[&n == &v.back()]
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
const int MAXN = 105;
const int mod = 1e9+7;

struct Mat {
    ll A[MAXN][MAXN];
    int n;
    Mat(int _n){
        n=_n;
        memset(A, 0, sizeof(A));
    }
    void pp(){
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < n; ++j) {
//                cout << A[i][j] << " \n"[j==n-1];
//            }
//        }
//        debug("-------------");
    }
};

Mat operator *(const Mat &m1, const Mat &m2) {
    assert(m1.n == m2.n);
    int n = m1.n;
    Mat ret(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                ret.A[i][j] += m1.A[i][k] * m2.A[k][j];
                ret.A[i][j] %= mod;
            }
        }
    }
    return ret;
}

Mat pow (Mat a, int n) {
    Mat ans(a.n);
    for (int i = 0; i < a.n; ++i) {
        ans.A[i][i]=1;
    }
    for (int i=1;i<=n;i<<=1) {
        if (n&i) ans = ans * a;
        a = a * a;
//        debug(i);
        a.pp();
    }
//    cerr << "ANS\n";
    ans.pp();
    return ans;
}

signed main() {_
    int n,m,l;
    cin >> n >> m >> l;
    Mat adj(n);
    for ( int i = 0; i < m; ++i) {
        int a,b;
        cin >> a >> b;
        adj.A[a-1][b-1] = 1;
    }
    
    adj.pp();
    auto af = pow(adj, l);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << af.A[i][j] << " \n"[j==n-1];
        }
    }
    
    
    return 0;
}
