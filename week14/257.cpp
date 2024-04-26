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

int n,m;

struct SegmentTree{
    struct node{
        int zero=1,one=0,two=0;
        int addtag = 0;
        int resettag = 0;
        void reset(){
            zero = zero + one + two;
            one = 0;
            two = 0;
            addtag = 0;
            resettag = 1;
        }
        void plus(int x){
            addtag+=x;
            x = x%3;
            while (x--) {
                debug(x,zero,one,two);
                swap(zero,one);
                swap(zero,two);
                debug(zero,one,two);
            }
        }
    };
    node st[2000005];
    // 用github思維
    void push(int i) {
        i/=2;
        while (i) {
            st[i].zero = st[i*2].zero + st[i*2+1].zero;
            st[i].one = st[i*2].one + st[i*2+1].one;
            st[i].two = st[i*2].two + st[i*2+1].two;
            i/=2;
        }
    }
    void pull(int i) {
        if (i==1)return;
        pull (i>>1);
        if (st[i>>1].resettag) {
            st[i].reset();
            st[i^1].reset();
            st[i>>1].resettag = 0;
        }
        st[i].plus(st[i>>1].addtag);
        st[i^1].plus(st[i>>1].addtag);
        st[i>>1].addtag = 0;
    }
    void turn(int l , int r) {
        for (l+=n, r+=n ; l < r ; l>>=1, r>>=1) {
            debug("turn",l,r);
            if (l&1){
                pull(l);
                st[l].plus(1);
                push(l);
                l++;
            }
            if (r&1){
                --r;
                pull(r);
                st[r].plus(1);
                push(r);
            }
        }
    }
    void reset(int l, int r){
        l += n;
        r += n;
        while (l < r) {
            if (l&1) {
                pull(l);
                st[l].reset();
                push(l);
                l++;
            }
            if(r&1){
                --r;
                pull(r);
                st[r].reset();
                push(r);
            }
            l>>=1;
            r>>=1;
        }
    }
    int query(int l , int r){
        int ans = 0;
        l += n;
        r += n;
        while (l < r) {
            if (l&1) {
                pull(l);
                ans += st[l].zero;
                l++;
            }
            if (r&1) {
                --r;
                pull(r);
                ans += st[r].zero;
            }
            l>>=1;
            r>>=1;
        }
        return ans;
    }
}seg;


signed main() {_
    cin >> n >> m;
    for(int i=0;i<n;i++){
        seg.push(i+n);
    }
    for(int i = 0; i < m; ++i){
        string type;
        int a ,b;
        cin >> type >> a >> b;
        a--;
        if (type == "TURN") {
            seg.turn(a,b);
        }
        if (type == "RESET") {
            seg.reset(a,b);
        }
        if (type == "COUNT") {
            cout << seg.query(a,b) << endl;
        }
    }
    
    
    return 0;
}
