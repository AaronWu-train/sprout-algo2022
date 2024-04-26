#pragma GCC optimize("Ofast")
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

inline ll pow(ll a, ll k){
    ll ans = 1;
    for (int i = 1; i <= k; i<<=1) {
        if(i&k) ans = ans * a;
        a = a * a;
    }
    return ans;
}

int main() {_
    int t;
    cin >> t;
    while (t--) {
        ll child;
        cin >> child;
        ll ori = child;
        if (ori == 1) {
            cout << 1 << endl;
            continue;
        }
        vector<ll>parent(10);
        for (int i = 9; i > 1; --i) {
            while (child%i == 0) {
                parent[i]++;
                child /= i;
            }
        }
        ll check = 1;
        for (int i = 1; i <= 9; ++i) {
            check*=pow(i, parent[i]);
        }
//
//        #ifdef DEBUG
//        debug(check);
//        #endif
        
        if (check != ori) {
            cout << -1 << endl;
        } else {
            for (int i = 1; i <= 9; ++i) {
                for (int j = 1; j <= parent[i]; ++j) {
                    cout << i;
                }
            }
            cout << endl;
        }
    }
    
    
    
    
    return 0;
}
