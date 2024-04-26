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



int main() {_
    auto seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::mt19937 rng(seed);
    int n,q;
    cin>>n>>q;
    vector <int> a(n+5);
    vector <int> pos[n+5];
    for (int i = 1; i <= n ; i++ ) {
        cin >> a[i] ;
        pos[a[i]].push_back(i);
    }
    for (int times = 0; times < q; times++) {
        int l,r;
        cin >> l >> r;
        int k = 30;
        bool tf = 1;
        for (int i = 0 ; i < k; i++ ) {
            int temp = uniform_int_distribution<int>(l, r)(rng);
            int cur = a[temp];
            auto left = lower_bound(pos[cur].begin(), pos[cur].end(), l);
            auto right = upper_bound(pos[cur].begin(), pos[cur].end(), r);
            ll temp3 = right - left;
            if (temp3 >(r-l+1)/2){
                cout << cur << endl;
                tf = 0;
                break;
            }
        }
        if(tf)cout << 0 << endl;
    }
    
    return 0;
}

