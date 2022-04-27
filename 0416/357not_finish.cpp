#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <bitset>
using namespace std;
#define All(x) begin(x),end(x)
#define ll long long int
#define endl '\n'
#define print(v) cerr<<#v<<": "; for(auto& n: v) cerr << n << " \n"[&n == &v.back()]
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

vector <ll> segtree, a;
inline void pull(int x) {
    segtree[x] = max(segtree[2 * x], segtree[2 * x + 1]);
}
void build(int l, int r, int cur) {
    if(l == r) {
        segtree[cur] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, 2 * cur); build(mid + 1, r, 2 * cur + 1);
    pull(cur);
}
void modify(int p, int v, int l, int r, int cur) {
    if(l == r) {
        segtree[cur] = v;
        return;
    }
    int mid = (l + r) / 2;
    if(p <= mid) modify(p, v, l, mid, 2 * cur);
    else modify(p, v, mid + 1, r, 2 * cur + 1);
    pull(cur);
}
ll query(int ql, int qr, int l, int r, int cur) {
    if(ql == l && qr == r) return segtree[cur];
    int mid = (l + r) / 2;
    if(qr <= mid) return query(ql, qr, l, mid, 2 * cur);
    else if(mid < ql) return query(ql, qr, mid + 1, r, 2 * cur + 1);
    return max(query(ql, mid, l, mid, 2 * cur), query(mid + 1, qr, mid + 1, r, 2 * cur + 1));
}

signed main() {_
    int n,m,r;
    cin >> n >> m>> r;
    a.resize(n+3);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    return 0;
}
