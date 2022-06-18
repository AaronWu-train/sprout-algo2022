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

struct SegmentTree{
    struct node{
        ll value = 0;
        ll tag = 0;
        void add(ll x) {
            value += x;
            tag += x;
        }
    };
    int n;
    vector<node>st;
    void init(int x, vector<ll>& arr) {
        n = x;
        st.resize(2*n+5);
        for (int i = 0; i < x; ++i) {
            st[i+x].value = arr[i];
        }
        for (int i = x-1; i > 0; --i) {
            st[i].value = max(st[i*2].value, st[i*2+1].value);
        }
    }
    
    void pull (int i) {
        if (i==1) return;
        pull(i>>1);
        st[i].add(st[i>>1].tag);
        st[i^1].add(st[i>>1].tag);
        st[i>>1].tag = 0;
    }
    void push (int i) {
        i >>= 1;
        while (i) {
            st[i].value = max(st[i*2].value, st[i*2+1].value);
            i>>=1;
        }
    }
    ll query(int l, int r){
        l += n;
        r += n;
        ll ans = INT_MIN;
        while (l < r) {
            if (l & 1) {
                pull(l);
                ans = max(ans, st[l].value);
                l++;
            }
            if (r & 1) {
                --r;
                pull(r);
                ans = max(ans, st[r].value);
            }
            l >>= 1;
            r >>= 1;
        }
        return ans;
    }
    void modify(int l, int r, int x){
        l += n;
        r += n;
        while (l < r) {
            if (l & 1) {
                pull(l);
                st[l].add(x);
                push(l);
                l++;
            }
            if (r & 1) {
                --r;
                pull(r);
                st[r].add(x);
                push(r);
            }
            l >>= 1;
            r >>= 1;
        }
    }
}seg;

signed main() {_
    int n, q;
    cin >> n >> q;
    vector<ll>arr(n);
    for (auto &i : arr) cin >> i;
    seg.init(n, arr);
    while (q--) {
        int type;
        cin >> type;
        int l,r,x;
        switch (type) {
            case 1:
                cin >> l >> r >> x;
                seg.modify(l-1, r, x);
                break;
            case 2:
                cin >> l >> r;
                cout << seg.query(l-1, r) << endl;
                break;
        }
    }
    return 0;
}
