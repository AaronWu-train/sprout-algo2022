#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long int
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
ll sx,sy,ex,ey,xx,yy;
bool touch(ll a,ll b){
    return (a == xx || b == yy);
}
int main() {_
    ll n,m,q;
    ll ans = 0;
    cin >> n >> m >> q;
    for (ll i = 0; i < q; i++) {
        cin >> sx >> sy >> ex >> ey >> xx >> yy;
        if (sx == ex && sy == ey) {
            ans++;
        }else if (touch(sx , sy)&&touch(ex, ey)){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
