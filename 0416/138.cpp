#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <bitset>
#include <queue>
#include <stack>
#define All(x) begin(x),end(x)
#define ll long long int
#define endl '\n'
#define print(v) cerr<<#v<<": "; for(auto& n: v) cerr << n << " \n"[&n == &v.back()]
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const int mod = 1000007;

void process(){
    
}

signed main() {_
    int t;
    cin >> t;
    vector<vector<ll>> arr(100005,vector<ll>(3,0));
    arr[0][0] = 1;
    arr[1][0] = 0;
    arr[1][1] = 0;
    arr[1][2] = 2;
    
    for (int i = 2; i<=100001; ++i) {
        arr[i][0] = (arr[i-1][2] + arr[i-2][0])%mod;
        arr[i][1] = arr[i-1][2];
        arr[i][2] = (arr[i-1][1] + arr[i-1][0]*2)%mod;
    }
    
    while (t--) {
        int n;
        cin >> n;
        cout << arr[n][0]%mod << endl;
    }
    
    return 0;
}
