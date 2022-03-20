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
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int main() {_
    int t;
    cin >> t;
    while (t--) {
        int h = 0,w = 0;
        cin >> h >> w;
//        vector<string>arr(h+2);
        vector<vector<int>>arr(h+2,vector<int>(w+2,0));
        for (int i = 0; i < h; ++i) {
            arr[0].push_back('#');
            arr[h+1].push_back('#');
        }
        arr[h+1]=arr[0];
//        debug(arr[0]);
//        debug(arr[h+1]);
        for (int i = 1; i <= h;++i) {
            string temp;
            cin >> temp;
            for (int j = 0; j < w; ++j) {
                arr[i][j+1] =(bool) (temp[j]=='.');
            }
        }
        bitset<1005>visited[1005] = {0};
        int ans = 0;
        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= w; ++j) {
                if (!visited[i][j] && arr[i][j]) {
                    ans++;
                    visited[i][j]= 1;
                    queue<pair<int, int>>bfs;
                    bfs.push(make_pair(i, j));
                    while (!bfs.empty()) {
                        auto cur = bfs.front();
                        bfs.pop();
                        for (int k = 0; k < 4; ++k) {
                            if (!visited[cur.first+dx[k]][cur.second+dy[k]] && arr[cur.first+dx[k]][cur.second+dy[k]]) {
                                bfs.push(make_pair(cur.first+dx[k], cur.second+dy[k]));
                                visited[cur.first+dx[k]][cur.second+dy[k]] = 1;
                            }
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
