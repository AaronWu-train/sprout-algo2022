#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <bitset>
#include <queue>
#define All(x) begin(x),end(x)
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main() {_
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        ll  total = 0;
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        cin >> n;
        for (int i=0; i<n; ++i) {
            int temp;
            cin >> temp;
            pq.push(temp);
        }
        
        while (pq.size()>1) {
            ll a = pq.top();
            pq.pop();
            a += pq.top();
            pq.pop();
            total += a;
            pq.push(a);
        }
        cout << total << '\n';
    }
    return 0;
}

