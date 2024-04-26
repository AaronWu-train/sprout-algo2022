#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#define ll long long int
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
ll n,m,q;
deque<deque<ll> >paper;
int main() {_
    cin >> n >> m >> q;
    for (int i = 0; i < n; ++i) {
        deque<ll>temp;
        for (int j = 0; j < m; ++j) {
            int a;
            cin >>a;
            temp.push_back(a);
        }
        paper.push_back(temp);
    }
    while (q--) {
        
        string type;
        int k;
        cin >> type >> k;
        if (type == "R") {
            for (int i = 1; i <= k ; i++) {
                for (auto &cur : paper) {
                    cur[m-2*k+i-1]+=cur[m-i];
                    cur.pop_back();
                }
            }
            m-=k;
        }
        if (type == "L") {
            for (int i = 0; i < k; i++) {
                for (int j = 0; j < n; j++) {
                    paper[j][2*k-1-i]+=paper[j][i];
                }
            }
            for (int i = 0; i < k; i++) {
                for (int j = 0; j < n; j++) {
                    paper[j].pop_front();
                }
            }
            m-=k;
        }
        if (type == "U") {
            for (int i = 0; i < k; i++) {
                for (int j = 0; j < m; j++) {
                    paper[2*k-i-1][j]+=paper[i][j];
                }
            }
            for (int i = 0; i < k; i++) {
                paper.pop_front();
            }
            n-=k;
        }
        if (type == "D") {
            for (int i = 1; i <= k  ; i++) {
                for (int j = 0; j < m; j++) {
                    paper[n-k-k+i-1][j]+=paper[n-i][j];
                }
                paper.pop_back();
            }
            n-=k;
        }

    }
    cout << n << " " << m << endl;
    for (auto &cur : paper) {
        for(auto a : cur){
            cout << a << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
