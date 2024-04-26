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

int n;
struct segment_tree{
    struct node{
        int l;
        int r;
        ll sum;
        ll lmaxsum;
        ll rmaxsum;
        ll ans;
    };
    vector<node>st;
    
        node combine(const node &a,const node &b){
            node ret;
            ret.sum = a.sum + b.sum;
            ret.lmaxsum = max(a.lmaxsum,a.sum+b.lmaxsum);
            ret.rmaxsum = max(b.rmaxsum,b.sum+a.rmaxsum);
            ret.ans = max({a.ans,b.ans,a.rmaxsum+b.lmaxsum});
            return ret;
        }
    
    void init(int l, int r, int i, vector<ll>&arr) {
        st[i].l = l;
        st[i].r = r;
        if (r-l==1) {
            st[i].sum = st[i].ans = st[i].lmaxsum = st[i].rmaxsum = arr[l];
            return;
        }
        int mid = (l+r)/2;
        init(l, mid, i<<1, arr);
        init(mid, r,2*i+1, arr);
        st[i] = combine(st[i*2], st[i*2+1]);
        st[i].l = l;
        st[i].r = r;
    }
    
    node query(int ql, int qr, int i) {
        auto &cur = st[i];
        if (cur.l == ql && cur.r == qr) {
            return cur;
        }
        int mid = (cur.l+cur.r)/2;
        if (qr <= mid) return query(ql, qr, i*2);
        if (mid <= ql) return query(ql, qr, i*2+1);
        return combine(query(ql, mid, i*2), query(mid, qr, i*2+1));
    }
    
}seg;

signed main() {_
    int n, q;
    cin >> n >> q;
    seg.st.resize(4*n);
    vector<ll>arr(n+5);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    seg.init(1, n+1, 1, arr);
    for (int i = 0; i < q; ++i) {
        int x,y;
        cin >> x >> y;
        cout << max(0ll,seg.query(x, y+1, 1).ans) << endl;
    }
    return 0;
}

