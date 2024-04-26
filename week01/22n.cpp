#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <stack>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;


int main() {_
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll>high;
        vector<ll>mono;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            high.push_back(temp);
            int to_pop = 0;
            while (mono.size() && mono.back()<temp) {
                to_pop++;
                mono.pop_back();
            }
            if (mono.size() && mono.back() == temp) {
                if (mono[0]==temp) {
                    to_pop+=mono.size();
                }else{
                    to_pop++;
                    auto p = equal_range(mono.begin(), mono.end(), temp, greater<int>());
                    to_pop += (p.second-p.first);
                }
            }else if(!mono.empty()){
                to_pop++;
            }
            ans += (ll)to_pop;
            mono.push_back(temp);
//            cerr << "DEBUG: ";
//            for (auto &i : mono) {
//                cerr << i << " ";
//            }
//            cerr << endl;
//            debug(ans);

        }
        cout << ans << endl;
    }
    
    
    
    
    
    
    return 0;
}
