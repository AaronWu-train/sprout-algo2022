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
struct BIT{
    ll arr[(int)1e6] = {0};
    void modify(int p, int v) {
        for(; p <= n; p += p & -p)
            arr[p] += v;
    }
    
    ll query(int q) {
        ll ret = 0;
        for(; q > 0; q -= (q & -q))
            ret += arr[q];
        return ret;
    }
}bit;

struct SegmentTree{
    struct node{
        ll winner = 0;
        ll winnerscore = 0;
        ll winnertime = 0;
        ll tag = 0;
        void add(int x){
            tag += x;
            winnerscore += x;
        }
    };
    vector<node>st;
    void init(int x, vector<ll>& arr) {
        st.resize(2*n+5);
        for (int i = 0; i < x; ++i) {
            st[i+x].winner = i;
            st[i+x].winnerscore = arr[i];
        }
        for (int i = x-1; i > 0; --i) {
            if (st[i*2].winnerscore >= st[i*2+1].winnerscore) {
                st[i].winner = st[i*2].winner;
                st[i].winnerscore = st[i*2].winnerscore;
//                st[i].winnertime = st[i*2].winnertime+1;
//                debug(st[i].winner);
                bit.modify(st[i].winner+1, 1);
            }
            else {
                st[i].winner = st[i*2+1].winner;
                st[i].winnerscore = st[i*2+1].winnerscore;
//                st[i].winnertime = st[i*2+1].winnertime+1;
                bit.modify(st[i].winner+1, 1);
            }
        }
    }
    void pull(int i) {
        if (i == 1) return;
        pull(i>>1);
        st[i].add(st[i>>1].tag);
        st[i^1].add(st[i>>1].tag);
        st[i>>1].tag = 0;
    }
    
    void push (int i) {
        i >>= 1;
        while (i) {
            bit.modify(st[i].winner+1, -1);
            if (st[i*2].winnerscore >= st[i*2+1].winnerscore) {
                st[i].winner = st[i*2].winner;
                st[i].winnerscore = st[i*2].winnerscore;
//                st[i].winnertime = st[i*2].winnertime+1;
                bit.modify(st[i].winner+1, 1);
            }
            else {
                st[i].winner = st[i*2+1].winner;
                st[i].winnerscore = st[i*2+1].winnerscore;
//                st[i].winnertime = st[i*2+1].winnertime+1;
                bit.modify(st[i].winner+1, 1);
            }
            i >>=1;
        }
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
    int m;
    cin >> n >> m;
    vector<ll>arr(n);
    for (auto &i : arr) cin >> i;
    seg.init(n, arr);
    for (int i = 0; i < m; ++i) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            ll l, r ,k;
            cin >> l >> r >> k;
            seg.modify(l-1, r, k);
        }
        else {
            ll l, r;
            cin >> l >> r;
            cout << (bit.query(r) - bit.query(l-1)) << endl;
        }
    }
    return 0;
}
