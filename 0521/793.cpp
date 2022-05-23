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
mt19937 gen(std::chrono::steady_clock::now().time_since_epoch().count());
std::uniform_int_distribution<int> unif(1, 1e8);
inline int next() {
    return unif(gen);
}
inline int mp(int n){
 
     n = ((n >> 16) ^ n) * 0x45d9f3b;
    n = ((n >> 16) ^ n) * 0x45d9f3b;
    n = (n >> 16) ^ n;// from stack overflow(a uniform hash function for int32);
    return n;
}

signed main() {_
    
    int n,k,q;
    cin >> n >> k >> q;
    vector<int>arr(5e5+5,0);
    vector<int>hash(5e5+5,0);
    vector<int>countt(5e5+5);
    
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        if (countt[a]==0) hash[a]=next();
        countt[a]++;
        if (countt[a]%k==0) arr[i] = (-1ll*hash[a]*(k-1))%mod;
        else arr[i]=hash[a];
    }
    
    for (int i = 1; i<=n; i++) {
        arr[i] = (arr[i]+arr[i-1])%mod;
    }
    
    for (int i = 0; i<q; i++) {
        int l,r;
        cin >> l >> r;
        cout <<((arr[r]-arr[l-1])%mod==0);
    }
    cout << endl;
    return 0;
}
/*
 
 10 2 10
 1 2 3 2 4 4 3 1 3 1
 1 8
 1 10
 5 6
 1 4
 5 10
 2 7
 1 7
 8 9
 7 9
 3 7
 
 */
