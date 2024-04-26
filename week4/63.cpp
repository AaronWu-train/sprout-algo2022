#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;


int main() {_
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        vector<int>arr(k);
        for (auto &i : arr) cin >> i;
        std::vector<int> v = {1,1,1,1,1,1};
        for (int i = 6; i < k; ++i) {
            v.push_back(0);
        }
        do{
            int temp = 0;
            for (int i = 0; i < k; ++i) {
                if (v[i]) {
                    cout << arr[i];
                    temp++;
                    if (temp != 6) cout << " ";
                    else cout << endl;
                }
            }
        }while(next_permutation(v.begin(), v.end(),greater<int>()));
    }
    
    return 0;
}
