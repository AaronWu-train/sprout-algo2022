#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>
#include <bitset>
#define All(x) begin(x),end(x)
#define ll long long int
#define endl '\n'
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#ifdef AaW
#   define debug(x) cerr<<#x<<" = "<<(x)<<endl
#else
#   define debug(x) 0
#endif

using namespace std;

int n,m;
bool check(int num, priority_queue<int> pq,vector<int> fruit){
    for (int i = num-1; i>=0; --i) {
        if (fruit[i]<=pq.top()) {
            int x = pq.top()-fruit[i];
            pq.pop();
            pq.push(x);
        }else{
            return 0;
        }
    }
    return 1;
}

signed main() {_
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        priority_queue<int> box;
        vector<int>fruit(m);
        for (int i = 0; i < n; ++i) {
            int te;
            cin >> te;
            box.push(te);
        }
        for (auto &th : fruit) cin >> th;
        sort(All(fruit));
        
        int l = 0, r = m+1;
        if (box.top() < fruit[0]) {
            cout<<0<<'\n';
            continue;
        }
//        if (check(m,box,fruit)) {
//            cout<<m<<'\n';
//            continue;
//        }
        while (l < r) {
            int mid = l + (r-l)/2;
//            debug(mid);
            if (check(mid,box,fruit)){
                l = mid+1;
            } else {
                r = mid;
            }
        }
        cout << l-1 << endl;
    }
    return 0;
}
