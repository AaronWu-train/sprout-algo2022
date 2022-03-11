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
    stack<ll>a;
    int n;
    cin>> n;
    bool ttt = 1;
    while (n--) {
        ll temp;
        cin >> temp;
        if (temp<0){
            if (a.empty()||(a.top()!=(-temp))) {
                ttt=0;
            }else{
                a.pop();
            }
        }else{
            a.push(temp);
        }
    }
    if (!ttt||!a.empty()) {
        cout << "lose light light" << endl;
    }else{
        cout << "weed" << endl;

    }
   
    
    
    
    return 0;
}
