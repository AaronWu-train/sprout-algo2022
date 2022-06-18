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

struct segment_tree{
    vector<int>st;
    void init(int l, int r, int id, vector<int>& arr){
        if (l==r-1) {
            st[id] = arr[l];
            return;
        }
        int mid = (l+r)>>1;
        init( l, mid, id<<1, arr);
        init(mid, r, id<<1^1, arr);
        st[id] = min(st[id<<1],st[id<<1^1]);
    }
    int query(int l, int r, int ql, int qr, int index){
        if (ql==l and r==qr) {
            return st[index];
        }
        int mid = (l+r)>>1;
        if (qr <= mid) return query(l, mid, ql, qr, index*2);
        if (ql >= mid) return query(mid, r, ql, qr, 2*index+1);
        return min(query(l, mid, ql, mid, 2*index), query(mid, r, mid, qr, 2*index+1));
    }
    void modify(int l, int r, int x, int v, int index){
        if (l == x and r == l+1) {
            st[index] = v;
            return;
        }
        int mid = (l+r)/2;
        if (x < mid) {
            modify(l, mid, x, v, 2*index);
        }
        else {
            modify(mid, r, x, v, index*2+1);
        }
        st[index] = min(st[index*2], st[index*2+1]);

    }
}seg;


signed main() {_
    int t,n;
    cin >> t >> n;
    vector<int>arr(n,0);
    for (int i = 0; i < n ; ++i) {
        cin >> arr[i];
    }
    seg.st.resize(4*n);
    seg.init(0, n, 1, arr);
    for (int i = 0; i < t; ++i) {
        int tp,x,y;
        cin >> tp >> x >> y;
        if (tp==1) {
            cout << seg.query(0, n, x, y+1, 1) << endl ;
        }
        else{
            seg.modify(0, n, x,y,1);
        }
    }
    
    
    return 0;
}
