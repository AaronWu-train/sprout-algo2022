#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <bitset>
#define All(x) begin(x),end(x)
#define ll long long int
#ifdef DEBUG
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#endif
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main() {_
    int t;
    cin >> t;
    while (t--) {
        int  n;
        ll   newStone;
        bool isHigh = 0;
        vector<ll> wall;
        cin >> n;
        cin >> newStone;
        wall.push_back(newStone);
        
        for (int i=1; i < n; ++i) {
            cin >> newStone;
            if (isHigh) {
                
                if (newStone <= wall.back()) {
                    wall.pop_back();
                } else {
                    isHigh = !isHigh;
                }
                wall.push_back(newStone);
                
            } else {
                
                if (newStone >= wall.back()) {
                    wall.pop_back();
                } else {
                    isHigh = !isHigh;
                }
                wall.push_back(newStone);
            }
            
            #ifdef DEBUG
            cerr << "DEBUG: ";
            for (auto j : wall) cerr << j << ' ';
            cerr << endl;
            #endif

        }
        
        if (wall.size()>=2 && wall.back() <= *(++wall.rbegin())) {
            wall.pop_back();
        }
        
        cout << wall.size() << endl;
        
    }
    
    return 0;
}
