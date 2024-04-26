#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define AI(x) begin(x),end(x)
#define ll long long
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

const int MOD = 712271227;
const int C = 59;
int mabs(int a) {
    return (a + MOD) % MOD;
}
int madd(int a, int b) {
    return mabs((a + b) % MOD);
}
int mmul(int a, int b) {
    return mabs((1ll * a * b) % MOD);
}

signed main() {_


    string s,t;
    cin >> s >> t;
    ll n = t.size();
    vector<int>cpow(n+5,1);
    vector<int>preh(n+5,0);
    for (int i = 0; i < n; ++i) {
        cpow[i+1] = mmul(cpow[i],C);
        preh[i+1] = madd(preh[i], mmul(t[i], cpow[i]));
    }
    

    int sum = 0;
    for (int i = 0; i < s.size(); ++i) {
        sum = madd(sum, mmul(s[i], cpow[i]));

    }
    
    vector<int>ans;
    ll m = s.size();
    for (int i = 1; i+m-1 <= n; ++i) {
        if ( mabs(preh[i+m-1]-preh[i-1]) == mmul(sum, cpow[i-1]) ) {
            ans.push_back(i-1);
        }
    }

    sort(AI(ans));
    for (int i = 0; i < ans.size(); ++i) {
        if (i) cout<<' ';
        cout<<ans[i];
    }
    cout<<endl;
    return 0;
}
