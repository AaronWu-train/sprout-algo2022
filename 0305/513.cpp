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
    int n;
    cin >> n;
    vector<ll>house(n+5);
    for (int i = 0; i < n; ++i) {
        cin >> house[i];
    }
    stack<int>left;
    vector<int>leftans(n+5);
    for (int i = 0; i < n; ++i) {
        while (left.size()&&house[left.top()]>=house[i]) {
            left.pop();
        }
        if (left.empty()) {
            leftans[i]=i+1;
        }else{
            leftans[i] = i - left.top();
        }
        left.push(i);
    }
    stack<int>right;
    ll maxnum = 0;
    for (int i = n-1; i>=0; --i) {
        while (right.size()&&house[right.top()]>=house[i]) {
            right.pop();
        }
        ll rightans; 
        if (right.empty()) {
            rightans = n-i-1;
        }else{
            rightans = right.top()-i-1;
        }
        right.push(i);
        maxnum = max(house[i]*(rightans+leftans[i]), maxnum);
    }
     
    cout << maxnum << endl;
    
    
    
    return 0;
}
