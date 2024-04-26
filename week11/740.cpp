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
template<class I> void OI(I a, I b){ while(a < b) cerr << *a << " \n"[next(a) == b], ++a; }
#else
#define debug(...) 0
#define OI(...) 0
#endif
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int mod = 1e9+7;
random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> unif(1, (int)1e7);
inline int next() {
    return unif(gen);
}

int A[1501][1501] = {0};
int B[1501][1501] = {0};
int C[1501][1501] = {0};

signed main() {_
    int n,m,k;
    cin >> n >> m >> k;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            cin >> B[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> C[i][j];
        }
    }
    
    ll R[1505]={0};
    for (int i = 0; i < k; i++) {
        R[i] = next();
    }
    
    ll temp[1505]={0};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            temp[i] += (1ll*B[i][j]*R[j])%mod;
        }
    }
    
    ll temp2[1505]={0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp2[i] += (1ll*A[i][j]*temp[j])%mod;
        }
    }
    
    ll temp3[1505]={0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            temp3[i] += (1ll*C[i][j]*R[j])%mod;
        }
    }

//    for (int i = 0; i < k; ++i) cerr << R[i] << " "; cerr << endl;
//    for (int i = 0; i < m; ++i) cerr << temp[i] << " "; cerr << endl;
//    for (int i = 0; i < n; ++i) cerr << temp2[i] << " "; cerr << endl;
//    for (int i = 0; i < n; ++i) cerr << temp3[i] << " "; cerr << endl;

    
    for (int i = 0; i < n; i++) {
        if ((temp2[i]%mod)!=(temp3[i]%mod)) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
