#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <bitset>
#define All(x) begin(x),end(x)
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
ll a,b,c,d,s,m,T;

inline static ll distence(ll curtime){
    ll maxdis = 0;
    for (ll i = 0; i < curtime; ++i) {
        ll curruntime = min((m+d*i)/c, curtime-i);
        ll curdis = a*(curtime-i-curruntime)+b*(curruntime);
        maxdis=max(maxdis, curdis);
    }
    return maxdis;
}

int main() {_
    cin >> a >> b >> c >> d >> m >> s >> T;
    ll l = 0, r = T;
    while (l < r) {
        ll mid = l + (r-l)/2;
        if (distence(mid)>=s) {
            r=mid;
        }else{
            l = mid+1;
        }
    }
    if (distence(l)<s){
        cout << "No\n";
        cout << distence(l) << '\n';
    }else{
        cout << "Yes\n";
        cout << l << '\n';
    }
    
    return 0;
}
