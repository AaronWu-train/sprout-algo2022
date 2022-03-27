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

int n;
int m;
ll total;
vector<int>c;
bool testx(ll);

int main() {_
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        c.clear();
        c.resize(n);
        for (auto &i : c) {
            cin >> i;
            total+=i;
        }
        ll l = 0, r = total;
        while (l < r) {
            ll mid = l + (r-l)/2;
            if (testx(mid)) {
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        cout << l << endl;
    }
    return 0;
}

bool testx(ll x){
    ll count = 0, cur = 0;
    for (int i = 0 ; i < n; ++i) {
        if (c[i] > x) {
            return 0;
        }
        if (cur + c[i] > x) {
            cur = 0;
            count++;
        }
        cur += c[i];
    }
    return count < m;
}
