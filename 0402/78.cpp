#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <bitset>
#include <cmath>
#define All(x) begin(x),end(x)
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main() {_
    int t;
    cin >> t;
    while (t--) {
        ll ans = 0;
        ll emptyspacefor1 = 0;
        vector<ll>boxsize(6);
        for (auto &i : boxsize) cin >> i;
//        if (boxsize[0]==0 && boxsize[1]==0 && boxsize[2]==0 &&boxsize[3]==0 && boxsize[4]==0 && boxsize[5]==0) {
//           break;
//        }
        
        ans += boxsize[5]; // 6x6
        ans += boxsize[4]; //5x5
        emptyspacefor1 += boxsize[4]*11;
        ans += boxsize[3]; //4x4
        if (boxsize[1] > boxsize[3]*5) boxsize[1]-=5*boxsize[3];
        else {
            emptyspacefor1 += 4*(boxsize[3]*5-boxsize[1]);
            boxsize[1] = 0;
        }
        
        ans += boxsize[2]/4; //3*3
        boxsize[2] = boxsize[2]%4;
        if (boxsize[2]) {
            ans++;
            ll roomfor2 = 7-2*boxsize[2];
            emptyspacefor1 += 8-boxsize[2];
            if (boxsize[1] >= roomfor2) boxsize[1] -= roomfor2;
            else {
                emptyspacefor1 += 4*(roomfor2 -  boxsize[1]);
                boxsize[1] = 0;
            }
        }
        
        ans += boxsize[1]/9;
        boxsize[1] = boxsize[1]%9;
        if (boxsize[1]) {
            ans++;
            emptyspacefor1 += (36 - 4*boxsize[1]);
        }
        
        boxsize[0] -= emptyspacefor1;
        
        if (boxsize[0] > 0) {
            ans += ceil((double)boxsize[0]/36.0);
        }
        cout << ans << endl;
    }
    return 0;
}
