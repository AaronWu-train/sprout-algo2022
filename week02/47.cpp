#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <set>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;


int main() {_
    set<int>p;
    int n;
    cin >> n;
    while (n--) {
        string type;
        cin >> type;
        if (type[0] == 'i') {
            int temp;
            cin >> temp;
            p.insert(temp);
        }else if(type[0] == 'd'){
            int temp;
            cin >> temp;
            p.erase(temp);
        }else{
            int temp;
            cin >> temp;
            auto big_it = p.lower_bound(temp);
            if (big_it == p.begin()) {
                cout << *(big_it) << endl;
            }else if(big_it == p.end()){
                cout << *(p.rbegin()) << endl;
            }else{
                auto small_it = big_it;
                small_it--;
//                debug(*small_it);
                if (*big_it - temp < temp - *small_it) {
                    cout << *(big_it) << endl;
                }else if (*big_it - temp == temp - *small_it){
                    cout << *small_it << ' ' << *big_it << endl;
                }else{
                    cout << *(small_it) << endl;
                }
            }
        }
    }
    
    
    
    
    return 0;
}
