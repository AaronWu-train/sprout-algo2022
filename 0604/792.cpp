#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii;
#define AI(x) begin(x),end(x)
#ifdef DEBUG 
#define debug(args...) LKJ("\033[1;32m[ "+string(#args)+" ]\033[0m", args)
template<class I> void LKJ(I&&x){ cerr << x << '\n'; }
template<class I, class...T> void LKJ(I&&x, T&&...t){ cerr << x << ", ", LKJ(t...); }
template<class I> void OI(I a, I b){ while(a < b) cerr << *a << " \n"[next(a) == b], ++a; }
#else
#define debug(...) 0
#define OI(...) 0
#endif

typedef pair<ll,ll> pt;
#define X first
#define Y second
ll operator ^ (const pt& a, const pt& b) {
    return a.X*b.Y - b.X*a.Y;
}


int main(){
    int n;
    while(cin >> n){
        vector<pt>arr;
        for(int i = 0; i < n; ++i){
            pt a;
            cin >> a.X >> a.Y;
            arr.push_back(a);
        }
        arr.push_back(arr[0]);
        ll area = 0;
        ll line = 0;
        for(int i = 0; i < n; ++i) {
            area += arr[i]^arr[i+1];
            if(arr[i].X == arr[i+1].X){
                line += abs(arr[i].Y - arr[i+1].Y);
            }
            if(arr[i].Y == arr[i+1].Y){
                line += abs(arr[i].X - arr[i+1].X);
            }
        }
        area = abs(area);
        if (line%2) {
            cout << area - line/2 -1 << ".5" << endl;
        }
        else {
            cout << area - line/2 << ".0" << endl;
        }

    }


	return 0;
}
