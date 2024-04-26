#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <bitset>
#include <list>
#include <deque>
#ifdef DEBUG
#   define print(v) cerr<<#v<<": ";for(auto& n:v) cerr<<n<<" \n"[&n == &v.back()]
#   define debug(x) cerr<<#x<<" = "<<(x)<<endl
#else
#   define print(v) 0
#   define debug(x) 0
#endif
#define All(x) begin(x),end(x)
#define ll long long int
#define pii pair<int,int>
#define endl '\n'
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;


signed main() {_
    int k,q;
    cin >> k >> q;
    list<ll>arr;
    bool reverse = 0;
    auto midptr = arr.begin();
    int midptrpos = 0;
    int arrsize = 0;
//    int headnomod = 0;
//    int tailnomod = 0;
    int modcount = 0;
    deque<string>ask;
    deque<int>addn;
    for (int i = 0; i < q; ++i) {
        string t;
        cin >> t;
        if (t=="Add") {
            int f;
            cin >> f;
            addn.push_back(f);
        }
        if (t=="Mod") {
            modcount++;
        }
        ask.push_back(t);
    }
    for (int count = 0; count < q; count++) {
        
//        cout << "debug: ";
//        if (reverse) {
//            for (auto i = arr.rbegin(); i!=arr.rend(); i++) {
//                cout << *i << " ";
//            }
//        }else{
//            for (auto i = arr.begin(); i!=arr.end(); i++) {
//                cout << *i << " ";
//            }
//        }
//        cout << endl;
//        debug(midptrpos);
//        debug(*midptr);
//        cout << endl;
//
        string type;
        type = ask.front();
        ask.pop_front();
        if (type[0] == 'A') {
            int temp;
            temp = addn.front();
            addn.pop_front();
            if (reverse) {
                arr.push_front(temp);
                midptrpos++;
//                headnomod++;
            }else{
                arr.push_back(temp);
//                tailnomod++;
            }
            arrsize++;
            if (arrsize==1) {
                midptr = arr.begin();
                midptrpos = 1;
            }
            int k = (arrsize+1)/2;
            while (midptrpos<k) {
                midptrpos++;
                midptr++;
            }
            while (midptrpos>k) {
                midptrpos--;
                midptr--;
            }
            continue;
        }
        if (type == "Remove") {
            int k = (arrsize+1)/2;
            while (midptrpos<k) {
                midptrpos++;
                midptr++;
            }
            while (midptrpos>k) {
                midptrpos--;
                midptr--;
            }
            midptr = arr.erase(midptr);
            arrsize--;
            continue;
        }
        if (type[0] == 'M') {
            if (modcount == 1) {
                for (auto &i : arr) {
                    i%=k;
                }
            }else{
                modcount--;
            }
            continue;
        }
        if (type == "Reverse") {
            reverse = !reverse;
        }
    }
    
    if (reverse) {
        for (auto i = arr.rbegin(); i!=arr.rend(); i++) {
            cout << *i << " ";
        }
    }else{
        for (auto i = arr.begin(); i!=arr.end(); i++) {
            cout << *i << " ";
        }
    }
    cout << endl;
    return 0;
}
