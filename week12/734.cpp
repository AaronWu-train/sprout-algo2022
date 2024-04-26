#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define AI(x) begin(x),end(x)
#define ll long long
#define endl '\n'
#ifdef DEBUG
#define debug(args...) LKJ("[ "+string(#args)+" ]",args)
template<class I> void LKJ(I&&x){cerr << x << endl;}
template<class I, class ...T> void LKJ(I&&x, T&&...t){cerr << x << " "; LKJ(t...);}
template<class I> void OI(I a, I b){while(a!=b){cerr << *a << " \n"[next(a)==b],++a;}}
#else
#define debug(...) 0
#define OI(...) 0
#endif
#define _ ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

struct rd{
    int x;
    int y;
    ll w;
};
bool operator >(rd a,rd b){return a.w>b.w;}
bool operator <(rd a,rd b){return a.w<b.w;}

vector<int>djs(2e5+5);
int query(int k){
    if (k==djs[k]) return k;
    djs[k] = query(djs[k]);
    return djs[k];
}

void modify (int x,int y){
    int xA = query(x);
    int yA = query(y);
    if (xA!=yA) djs[xA] = yA;
}



signed main(){_
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) djs[i] = i;
    vector<rd>vec;
    for (int i = 0; i < m; ++i) {
        rd a;
        cin >> a.x >> a.y >> a.w;
        vec.push_back(a);
    }
    sort(AI(vec));
    ll ans = 0;
    for (auto& i : vec) {
        if (query(i.x)!=query(i.y)) {
            ans+=i.w;
            modify(i.x, i.y);
        }
    }
    cout << ans << endl;
}
