#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
//#include "lib1895.h"
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

struct SegmentTree{
    struct node{
        ll high = 5e5+5;
        ll low = 0;
        void add(ll h) {
            high = max(high,h);
            low = max(low,h);
        }
        void sub(ll h) {
            high = min(high,h);
            low = min(low,h);
        }
    };
    int n;
    vector<node>st;
    void init(int _n){
        n = _n;
        st.resize(2*n+5);
    }
    void pull(int i) {
        if (i == 1) return;
        pull(i>>1);
        if (st[i>>1].low!=0 || st[i>>1].high != 5e5+5) {
            st[i].add(st[i>>1].low);
            st[i^1].add(st[i>>1].low);
            st[i].sub(st[i>>1].high);
            st[i^1].sub(st[i>>1].high);
            st[i>>1].low = 0;
            st[i>>1].high = 5e5+5;
        }
    }
    
    void modifyadd(int l, int r, int x) {
        l+=n;
        r+=n;
        while (l < r) {
            if (l & 1) {
                pull(l);
                st[l].add(x);
//                push(l);
                l++;
            }
            if (r & 1) {
                r--;
                pull(r);
                st[r].add(x);
//                push(r);
            }
            l >>= 1;
            r >>= 1;
        }
    }
    void modifysub(int l, int r, int x) {
        l+=n;
        r+=n;
        while (l < r) {
            if (l & 1) {
                pull(l);
                st[l].sub(x);
//                push(l);
                l++;
            }
            if (r & 1) {
                r--;
                pull(r);
                st[r].sub(x);
//                push(r);
            }
            l >>= 1;
            r >>= 1;
        }
    }
}seg;

// for TIOJ
void buildWall(int n, int k, int op[], int l[], int r[], int h[], int finalHeight[]) {
    SegmentTree sss;
    sss.init(n);
    for (int i = 0; i < k; ++i) {
        if (op[i] == 1) sss.modifyadd(l[i], r[i]+1, h[i]);
        if (op[i] == 2) sss.modifysub(l[i], r[i]+1, h[i]);
    }
    for (int i = 0; i < n; ++i) {
        sss.pull(i+n);
        finalHeight[i] = (int) sss.st[i+n].low;
    }
}


signed main() {_
//    cout << __lg(10);
    int n, m;
    cin >> n >> m;
    seg.init(n);
    int op, l , r, h;
    for (int i = 0; i < m; ++i) {
        cin >> op >> l >> r >> h;
        if (op == 1) seg.modifyadd(l, r+1, h);
        if (op == 2) seg.modifysub(l, r+1, h);
    }
    for (int i = 0; i < n; ++i) {
        seg.pull(i+n);
        cout << min(seg.st[i+n].low, seg.st[i+n].high)  << endl;
    }
    return 0;
}
