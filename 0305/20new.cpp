#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <climits>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main() {_
    int t;
    cin >> t;
    for (int count = 1; count <= t; count++) {
        cout << "Line #"<<count<<endl;
        int n;
        cin >> n;
        vector<int>which_group(1000005,0);
        for (int i = 1; i <= n; i++) {
            int temp;
            cin >> temp;
            for (int j = 0; j < temp; j++) {
                int tem2;
                cin >> tem2;
                which_group[tem2]=i;
            }
        }
        int m;
        cin >> m;
        vector<queue<int>> groups(n+5);
        queue<int>line;
        while (m--) {
            string type;
            cin >> type;
            if (type[0]=='E') {
                int who;
                cin >> who;
                if (which_group[who] != 0) {
                    if (groups[which_group[who]].empty()) {
                        line.push(which_group[who]);
                    }
                    groups[which_group[who]].push(who);
                }else{
                    line.push(-who);
                }
            }else{
                if (line.front()<0) {
                    cout << -line.front() << endl;
                    line.pop();
                }else{
                    cout << groups[line.front()].front() << endl;
                    groups[line.front()].pop();
                    if (groups[line.front()].empty()) {
                        line.pop();
                    }
                }
                
            }
        }
    }
    return 0;
}
