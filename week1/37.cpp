#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;


int main() {_
    int t;
    cin >> t;
    queue<int>a;
    while (t--) {
        int type;
        cin >> type;
        if (type == 1) {
            int temp;
            cin >> temp;
            a.push(temp);
        }else{
            if (a.empty()) {
                cout << "empty!\n";
            }else{
                cout << a.front() << endl;
                a.pop();
            }
        }
    }
    
    
    
    
    
    
    return 0;
}

