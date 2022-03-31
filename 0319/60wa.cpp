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

inline static ll caculate(ll curtime){
    return (T-curtime)*a + (b-a)*min( ((m+d*curtime)/c), T-curtime );
}

int main() {_
    cin >> a >> b >> c >> d >> m >> s >> T;
    ll l = 0, r = T;
    while (l < r) {
        ll mid = l + (r-l)/2;
        if (caculate(mid) < caculate(mid+1)) {
            l = mid+1;
        }else{
            r = mid;
        }
    }
    if (caculate(l)<s) {
        cout << "No\n" << caculate(l) << '\n';
    }else{
        r = l;
        l = 0;
        while (l < r) {
            debug(1);
            ll mid = l + (r-l)/2;
            if (caculate(mid)>=s) {
                r = mid;
            }else{
                l = mid+1;
            }
        }
        debug(l);
        cout << "Yes\n" << T - l << '\n';
        
    }
    
    return 0;
}
