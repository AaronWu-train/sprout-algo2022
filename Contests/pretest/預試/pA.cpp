#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long int
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;

int main() {_
    ll n,m,k;
    vector<ll>snake;
    cin>>n>>m>>k;
    if (k==0) {
        cout<<(n*m)/6+((n*m)%6!=0)<<endl;
        return 0;
    }
    
    for (ll i = 0; i < k; i++) {
        ll tx,ty;
        cin >> tx >> ty;
        if(tx%2==0)ty = m-ty+1;
        snake.push_back((tx-1)*m+ty);
    }
    
    sort(snake.begin(), snake.end());
    
    ll aaa = 0;
    int count = 0;
    ll bbb = 0;
    for (int i = 0; i < snake.size(); i++) {
        bbb = snake[i];
        if (bbb-aaa == 1){
            count++;
            if (count > 5) {
                cout << -1 << endl;
                return 0;
            }
        }else{
            count = 0;
        }
        aaa = bbb;
    }
    
    ll back = 0;
    for (ll i = 0; i < snake.size();i++) {
        ll curback = 0;
        ll j = i;
        ll cur = snake[i];
        while ((cur+back+curback)%6==0) {
            curback++;
            if(cur-snake[j-1]==1){
                j--;
                cur = snake[j];
            }else{
                break;
            }
        }
        back += curback;
        
    }
    
    cout <<(n*m+back)/6+((n*m+back)%6!=0)<<endl;
    return 0;
}
