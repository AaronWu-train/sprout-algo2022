#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
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
        int n, m;
        cin >> n >> m;
        vector<int>people[n+2];
        for (int i = 0; i < m; ++i) {
            int tem1 , tem2;
            cin >> tem1 >> tem2;
            people[tem1].push_back(tem2);
            people[tem2].push_back(tem1);
        }
        bitset<100005>visited;
        queue<int>bfs;
        vector<int>gender(n,0);
        bool ok = 1;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]&&ok) {
                visited[i] = 1;
                gender[i] = 1;
                bfs.push(i);
                while (bfs.size()&&ok) {
                    auto person = bfs.front();
                    bfs.pop();
                    for (auto &k : people[person]) {
                            if (gender[k]==gender[person]) {
                                ok = false;
                                break;
                            }else if (!visited[k]){
                                gender[k] = -gender[person];
                                bfs.push(k);
                                visited[k]=1;
                            }
                    }
                }
            }
        }
        if (ok) {
            cout << "NORMAL.\n";
        }else{
            cout << "RAINBOW.\n";
        }
        
    }
    
    
    
    
    return 0;
}
