#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <bitset>
#define AI(x) begin(x),end(x)
#define ll long long int
#define endl '\n'
#define print(v) cerr<<#v<<": "; for(auto& n: v) cerr << n << " \n"[&n == &v.back()]
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

signed main() {_
    int t,n,m,cur;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<ll>lis;
        for (int i = 0; i < n; ++i) {
            cin >> cur;
            if (2*cur>=m) {
                auto it = upper_bound(AI(lis), 2*cur);
                if (it == lis.end()) lis.push_back(2*cur);
                else *it = 2*cur;
            }
            if (cur>=m) {
                auto it = upper_bound(AI(lis), cur);
                if (it == lis.end()) lis.push_back(cur);
                else *it = cur;
            }
        }
        cout << lis.size() << endl;
    }
    return 0;
}
