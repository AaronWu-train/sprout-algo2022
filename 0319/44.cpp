#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>
#include <bitset>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
struct pos{
    int x;
    int y;
    int times = 0;
    pos(int _x, int _y, int _times):x(_x),y(_y),times(_times){}
};

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int main() {_
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;
        vector<string>arr(n);
        pos catpos(0,0,0);
        bool catfound = 0;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            for (int j = 0; j < m; ++j) {
                if (!catfound && arr[i][j]=='K') {
                    catpos.x=i;
                    catpos.y=j;
                    catfound = 1;
                }
            }
        }
        bitset<105>visited[105] = {0};
        queue<pos>bfs;
        bfs.push(catpos);
        visited[catpos.x][catpos.y] = 1;
        int ans = 0;
        while (bfs.size()) {
            auto cur = bfs.front();
            bfs.pop();
            if (arr[cur.x][cur.y]=='@') {
                ans = cur.times;
                break;
            }
            for (int k = 0; k < 4; ++k) {
                if (!visited[cur.x+dx[k]][cur.y+dy[k]] && arr[cur.x+dx[k]][cur.y+dy[k]]!='#') {
                    bfs.push(pos(cur.x+dx[k], cur.y+dy[k],cur.times+1));
                    visited[cur.x+dx[k]][cur.y+dy[k]]=1;
                }
            }
        }
        if (ans) {
            cout << ans << endl;
        }else{
            cout << "= =\"\n";
        }
        
        
        
        
        
        
        
        
        
    }
    return 0;
}
