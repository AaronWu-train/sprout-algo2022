#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <bitset>
using namespace std;
#define All(x) x.begin(),x.end()
#define ll long long int
#define endl '\n'
#define print(v) cerr<<#v<<": "; for(auto& n: v) cerr << n << " \n"[&n == &v.back()]
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

vector <pair<int, int>> segtree;
inline void pull(int x) {
    segtree[x] = max(segtree[2 * x], segtree[2 * x + 1]);
}
void build(int l, int r, int cur, vector<pair<int, int>>&arr) {
    cerr << "b";
    if(l == r) {
//        cerr << l;
        segtree[cur].second = arr[l].second;
        segtree[cur].first = l;
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, 2 * cur,arr); build(mid + 1, r, 2 * cur + 1,arr);
    pull(cur);
}
void modify(int p, pair<int, int> v, int l, int r, int cur) {
    cerr << "m";
    if(l == r) {
        segtree[cur] = v;
        return;
    }
    int mid = (l + r) / 2;
    if(p <= mid) modify(p, v, l, mid, 2 * cur);
    else modify(p, v, mid + 1, r, 2 * cur + 1);
    pull(cur);
}
pair<int, int> query(int ql, int qr, int l, int r, int cur) {
    cerr<<'q';
    if(ql == l && qr == r) return segtree[cur];
    int mid = (l + r) / 2;
    if(qr <= mid) return query(ql, qr, l, mid, 2 * cur);
    else if(mid < ql) return query(ql, qr, mid + 1, r, 2 * cur + 1);
    auto r1 = query(ql, mid, l, mid, 2 * cur);
    auto r2 = query(mid + 1, qr, mid + 1, r, 2 * cur + 1);
    return max(r1,r2);
}

signed main() {_
    int n,m,rate;
    cin >> n >> m>> rate;
    segtree.resize(4*n);
    vector<pair<int, int>>spell(n+1,make_pair(0,0));
    for (int i = 1; i <= n; ++i) {
        cin >> spell[i].first >> spell[i].second;
    }
    sort(All(spell));
    build(1, n, 1, spell);
    long long time=0;
    long long DamPerSec = 0;
    long long health = m;
    pair<int,int> maxinrange = make_pair(0,-1);
    while (!(time>n && DamPerSec<=(long long) rate && maxinrange.first<=0 )) {
        health-=DamPerSec;
                health+=rate;
                health = min(health,(long long)m);
                if(health<=0) break;
                //Binary search for r
                int r=n;int l=-1;
                while(r-l>1){
                    int mid = l+((r-l)>>1);
                    if((long long)spell[mid].first*m >= (long long)health*100){
                        r=mid;
                    }else{
                        l=mid;
                    }
                }
                // in range [r,n-1] find the spells with the largest damage that hasn't been chosen yet
                maxinrange = query(r,n,1,n,1);
                DamPerSec += maxinrange.first;
                modify(maxinrange.first,make_pair(maxinrange.first, 0),1,n,1);
                //advance time
                ++time;
    }
    
    
    if((time>n && DamPerSec<=(long long) rate && maxinrange.first<=0 )){
           cout<<-1<<endl;
    } else{
           cout<<time<<endl;
    }
    
    
    return 0;
}
