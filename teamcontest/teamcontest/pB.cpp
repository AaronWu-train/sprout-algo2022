#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <algorithm>
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

signed main() {_
    std::random_device rd;
    std::mt19937 gen( rd() );

    int n, m;
    cin >> n >> m;
    vector<int>arr(n);
    int sum = 0;
    vector<bool>tf(n+1);
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        sum+=temp;
        tf[temp] = 1;
    }
    vector<int>haha(sum,0);
    int cur = 0;
    for (int i = 1; i <= n; ++i) {
        if (tf[i]) {
            for (int j = 0; j < i; ++j) {
                haha[cur++] = i;
            }
        }
    }
//    debug(cur);
    for (int i = cur; i < sum; ++i) {
        int t = uniform_int_distribution<int>(1,n)(gen);
        while (tf[t]) {
            t = uniform_int_distribution<int>(1,n)(gen);
        }
        haha[i] = t;
    }
//    OI(AI(haha));
    std::random_shuffle(haha.begin(), haha.end());
    
    for (int i = 0; i < m; ++i) {
        cout << haha[i%n] << " \n"[i==m-1];
    }
//    vector<bool>check(sum);
//    for (int i = 0; i < m; ++i) {
//        int k = uniform_int_distribution<int>(0,sum-1)(gen);
//        while (check[k]) {
//            k = uniform_int_distribution<int>(0,sum-1)(gen);
//        }
//        check[k] = 1;
////        debug(k);
//        cout << haha[k] << " \n"[i==m-1];
//    }
////    cout << endl;
    return 0;
}
