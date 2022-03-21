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
#define R 4 //100
#define Y 2 //010
#define B 1 //001
typedef char int8;
using namespace std;
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
        for (int i = 0; i < 3; ++i) {
            <#statements#>
        }
        
        
        
    }
    
    
    
    
    return 0;
}
