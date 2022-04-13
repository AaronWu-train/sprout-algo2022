#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <bitset>
#define All(x) begin(x),end(x)
#define ll long long int
#define endl '\n'
#ifdef DEBUG
#define print(v) cerr<<#v<<": "; for(auto& n: v) cerr << n << " \n"[&n == &v.back()]
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#else
#define print(v) 0
#define debug(x) 0
#endif
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
vector<int>dp[100005];

vector<int> fun(int n){
    if (!dp[n].empty()) {
        return dp[n];
    }
    
    int mid = n/2;
    auto l = fun(n-mid);
    auto r = fun(mid);
    vector<int>ret(n);
    int i = 0;
    while (i<(n-mid)) {
        ret[i] = 2*l[i]-1;
        ++i;
    }
    int j = 0;
    while (i < n) {
        ret[i] = r[j]*2;
        i++;
        j++;
    }
    dp[n] = ret;
    return ret;
}

signed main() {_
    int n;
    cin >> n;
    dp[1] = {1};
    auto ret = fun(n);
    for(int i = 0; i < n-1; ++i)cout << ret[i] <<" ";
    cout << ret[n-1] << endl;
    return 0;
}
