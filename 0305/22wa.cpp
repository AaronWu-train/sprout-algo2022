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
        vector<int>high;
        vector<int>value;
        stack<int>canBeAns;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            high.push_back(temp);
            value.push_back(1);
            while (!canBeAns.empty() && high[canBeAns.top()]<=temp) {
                ans+=value[canBeAns.top()];
                if (high[canBeAns.top()]==temp) {
                    value[i]++;
                }
                canBeAns.pop();
            }
            if (!canBeAns.empty()) {
                ans++;
            }
            canBeAns.push(i);
            
        }
        cout << ans << endl;
    }
    
    
    
    
    
    
    return 0;
}
