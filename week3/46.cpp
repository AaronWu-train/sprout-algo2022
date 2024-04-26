#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>
#include <map>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define R 4   //100
#define Y 2  //010
#define B 1 //001
typedef char int8;
using namespace std;
map<char, int8>colorTable = {{'Y',Y},{'R',R},{'B',B},{'O',(R|Y)},{'P',(R|B)},{'G',(B|Y)},{'D',7}};

int dx[] = {0,0,-1,1,-1,1,-1,1};
int dy[] = {-1,1,0,0,-1,-1,1,1};

struct node{
    int x;
    int y;
    int time;
    int8 color = 0;
    node(int x,int y,int time,int8 color = 0) : x(x),y(y),time(time),color(color){};
};

int main() {_
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int8>> graph(n+2,vector<int8>(n+2,0));
        queue<node>bfs;
        for (int i = 0; i < n+2; ++i) {
            graph[0][i]=7;
            graph[n+1][i]=7;
            graph[i][0]=7;
            graph[i][n+1]=7;

        }
        for (int i = 0; i < 3; ++i) {
            char type;
            int x;
            int y;
            cin >> type >> x >> y;
            x++;
            y++;
            graph[x][y] = colorTable[type];
            bfs.push(node(x,y,0,colorTable[type]));
        }
        char tem;
        cin >> tem;
        int8 chosencolor = colorTable[tem];
        int colorMax = 0;
        int curtime = (__builtin_popcount(chosencolor) == 1);
        int curMax = (__builtin_popcount(chosencolor) == 1);
        
        while (bfs.size()) {
            while (bfs.size()&& curtime >= bfs.front().time) {
                int& x = bfs.front().x;
                int& y = bfs.front().y;
                int8& nowcolor = bfs.front().color;

                for (int i = 0; i < 8; i++) {
                    int8& next = graph[x + dx[i]][y + dy[i]];
                    if ((next | nowcolor) == next) continue;
                    if (next==chosencolor) {
                        curMax--;
                    }
                    next |= nowcolor;
                    if (next==chosencolor) {
                        curMax++;
                    }
                    bfs.push(node(x + dx[i],y + dy[i], curtime+1, next));
                }

                bfs.pop();
            }
            colorMax = max(curMax, colorMax);
            curtime++;
        }
        cout << colorMax << endl;
        
    }
    
    
    
    
    return 0;
}
