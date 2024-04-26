#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
//#include <bits/stdc++.h>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define All(x) begin(x),end(x)
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int n,k;
vector<ll>a;
vector<ll>b;
vector<ll>c;
bool canWin(ll);

int main() {_
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        a.clear();
        b.clear();
        c.clear();
        a.resize(n);
        b.resize(n);
        c.resize(n);
        
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
        }
        for (auto& i : c) cin >> i;
        sort(c.begin(), c.end());
        ll l = 0, r = INT_MAX;
        while (l < r) {
            ll mid = l + (r-l)/2;
            if (canWin(mid)) r = mid;
            else l = mid+1;
        }
        if (canWin(l)) {
            cout << l << endl;
        }else{
            cout << -1 << endl;
        }
        
    }
    return 0;
}


bool canWin(ll day){
    vector<ll> horse = a;
    for (int i = 0; i < n; ++i) {
        horse[i] += b[i]*day;
    }
    sort(All(horse),greater<ll>());
    vector<ll> badC (c.begin(), c.begin()+k);
    for (int i = 0; i < k; ++i) {
        if (horse[i]<=badC[k-1-i]) return 0;
    }
    return 1;
}
