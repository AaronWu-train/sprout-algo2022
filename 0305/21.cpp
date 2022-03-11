#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <list>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;


int main() {_
    int n,m;
    cin >> n >> m;
    list<int>::iterator arr[n+5];
    list<int>a;
    for (int i = 1; i <= n; ++i) {
        a.push_back(i);
        arr[i] = (--a.end());
    }
    for (int i = 0; i < m; ++i) {
        int t,x;
        cin >> t >> x;
        if (t==0) {
            a.erase(arr[x]);
        }else{
            list<int>::iterator it = arr[x];
            if (it==a.begin()) {
                continue;
            }
            --it;
//            debug(*it);
//            debug(*arr[x]);
            a.erase(arr[x]);
            arr[x] = a.insert(it, x);
//            debug(*arr[x]);
        }
//        for (auto i = a.begin();i!=a.end();i++) {
//            cout << *i << " ";
//        }
//        cout << endl;
    }
    auto last = a.end();
    last--;
    for (auto i = a.begin();i!=last;i++) {
        cout << *i << " ";
    }
    cout << *last << endl;
    
    return 0;
}
