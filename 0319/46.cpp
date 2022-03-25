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
map<char, int8>colorTable = {{'Y',Y},{'R',R},{'B',B},{'O',R|Y},{'P',R|B},{'G',B|Y},{'D',7}};
struct node{
    int x;
    int y;
    int time;
    int8 color;
    node(int x,int y,int time,int8 color):x(x),y(y),time(time),color(color){};
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
            bfs.push(node(x,y,0,colorTable[type]));
        }
        char tem;
        cin >> tem;
        int8 chosencolor = colorTable[tem];
        
        
        
    }
    
    
    
    
    return 0;
}
