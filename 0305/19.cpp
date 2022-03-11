#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <stack>
#include <deque>
#include <bitset>
#include <queue>
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
        bool tf = 1;
        int cur = 1;
        queue<int>left;
        stack<int>mid;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            left.push(temp);
        }
        while (cur <= n+1 && !left.empty()) {
            if (mid.empty()||mid.top()!=left.front()) {
                mid.push(cur);
                cur++;
            }
            if (mid.top()==left.front()) {
                mid.pop();
                left.pop();
            }
        }
        if (mid.empty()) {
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }

        
        
    }
    
    
    
    
    return 0;
}

//
//for (int i = 0; i < n; i++) {
//    if (!mid.empty() && left[i]==mid.top()) {
//        mid.pop();
//        continue;
//    }else if(right.front() < left[i]){
//        tf = 0;
//        break;
//    }else{
//        while (right.front() > left[i]) {
//            mid.push(right.front());
//            right.pop_front();
//            if (right.empty()) {
//                tf = 0;
//                break;
//            }
//        }if(!tf&&right.front()==left[i]){
//            right.pop_front();
//        }
//    }
//    if (!tf) {
//        break;
//    }
//}
//if (tf) {
//    cout << "Yes\n";
//}else{
//    cout << "No\n";
//}
