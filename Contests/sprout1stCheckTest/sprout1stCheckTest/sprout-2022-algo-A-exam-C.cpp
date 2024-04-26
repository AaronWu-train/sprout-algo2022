#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <bitset>
#include <cmath>
#ifdef DEBUG
#   define print(v) cerr<<#v<<": ";for(auto& n:v) cerr<<n<<" \n"[&n == &v.back()]
#   define debug(x) cerr<<#x<<" = "<<(x)<<endl
#else
#   define print(v) 0
#   define debug(x) 0
#endif
#define All(x) begin(x),end(x)
#define ll long long int
#define pii pair<int,int>
#define endl '\n'
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;


signed main() {_
    int n,m,k;
    cin >> n >> m >> k;
    vector<int>cha(n+5,0);
    for (int i = 0; i < m; ++i) {
        int a,b;
        cin >> a >> b;
        cha[a]++;
        cha[b]--;
    }
    int sum = cha[0];
    int maxspace = 0;
    int maxhead = 0;
    int curhead = 0;
    int tail;
    int curspace = (sum==0);
    
    for (int i = 1; i < n; ++i) {
        sum+=cha[i];
        if (sum==0) {
            curspace++;
            tail = i;
        } else {
            if (maxspace <= curspace) {
                maxspace = curspace;
                maxhead = curhead;
            }
            curhead = i;
            curspace = 0;
        }
    }
    if (maxspace <= curspace) {
        maxspace = curspace;
        maxhead = curhead;
    }
    if (maxhead == 0 or maxhead+maxspace == n-1 or k==1) {
        cout << maxspace << endl;
    }else{
        cout << ceil(maxspace/2.0) << endl;
    }
    return 0;
}
