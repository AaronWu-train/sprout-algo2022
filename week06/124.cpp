#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <bitset>
#define endl '\n'
#define All(x) begin(x),end(x)
#define ll long long int
#ifdef DEBUG
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#else
#define debug(x) 0
#endif
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;


void Report(int ,int ,int ,int ,int ,int );

void mysolve(int N ,int X, int Y, int dx, int dy){
    int midx = dx+N/2-1;
    int midy = dy+N/2-1;
    if (X > midx) {
        if (Y > midy) { // rd
            Report(midx, midy, midx+1, midy, midx, midy+1);
            if (N!=2) {
                mysolve(N/2, midx, midy, dx, dy);
                mysolve(N/2, midx+1, midy, midx+1, dy);
                mysolve(N/2, midx, midy+1, dx, midy+1);
                mysolve(N/2, X, Y, midx+1, midy+1);
            }
        } else { // ru
            Report(midx, midy, midx+1, midy+1, midx, midy+1);
            if (N!=2) {
                mysolve(N/2, midx, midy, dx, dy);
                mysolve(N/2, X, Y, midx+1, dy);
                mysolve(N/2, midx, midy+1, dx, midy+1);
                mysolve(N/2, midx+1, midy+1, midx+1, midy+1);
            }
        }
    } else {
        if (Y > midy) { // ld
            Report(midx,midy,midx+1,midy,midx+1,midy+1);
            if (N!=2) {
                mysolve(N/2, midx, midy, dx, dy);
                mysolve(N/2, midx+1, midy, midx+1, dy);
                mysolve(N/2, X, Y, dx, midy+1);
                mysolve(N/2, midx+1, midy+1, midx+1, midy+1);
            }
        } else { // lu
            Report(midx+1, midy, midx+1, midy+1, midx, midy+1);
            if (N!=2) {
                mysolve(N/2, X, Y, dx, dy);
                mysolve(N/2, midx+1, midy, midx+1, dy);
                mysolve(N/2, midx, midy+1, dx, midy+1);
                mysolve(N/2, midx+1, midy+1, midx+1, midy+1);
            }
        }
    }
}

void solve(int N,int X,int Y){
    mysolve(N,X,Y,1,1);
}
int mcount = 0;
int arr[100][100];
void Report(int x1,int y1 ,int x2 ,int y2 ,int x3 ,int y3){
    mcount++;
    arr[x1][y1] = mcount;
    arr[x2][y2] = mcount;
    arr[x3][y3] = mcount;
}

#ifdef DEBUG
signed main() {_
    int n,x,y;
    cin >> n >> x >> y;
    solve(n, x, y);
    for (int i = 1; i <=n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
#endif
