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

int main() {_
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<pair<int, int>> arr;
        cin >> n;
        for (int i=0; i<n; ++i) {
            int c,e;
            cin >> c >> e;
            arr.push_back(make_pair(e, c));
        }
        sort(All(arr),greater<pair<int, int>>());
        
        ll curTime = 0;
        ll maxTime = 0;
        for (int i=0; i<n; ++i) {
            curTime = curTime+arr[i].second;
            maxTime = max(maxTime, curTime+arr[i].first);
        }
        cout << maxTime << endl;
    }
    return 0;
}
