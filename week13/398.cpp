#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define AI(x) begin(x),end(x)
#ifdef DEBUG
#define debug(args...) LKJ("[ "+string(args)+" ]", args)
template<class I>void LKJ(I&&a){cerr << a << endl;}
template<class I, class ...T>void LKJ(I&&a, T&&...t){cerr << a << " ";LKJ(t...);}
template<class I>void OI(I a, I b){ while(a!=b){cerr << *a << " \n"[next(a)==b]; ++a;}}
#else
#define debug(...) 0
#define OI(...) 0
#endif
const double eps = 1e-10;

bool is_equal(double a, double b) {
    return (b - eps < a)&&(a < b+eps);
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<double>arr(n+5);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                if (is_equal(arr[i]+arr[j],arr[k])) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}

