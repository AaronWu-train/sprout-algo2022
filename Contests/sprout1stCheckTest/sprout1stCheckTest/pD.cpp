#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <bitset>
#include <queue>
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
    int n,k;
    cin >> n >> k;
    vector<int>pri(n+5,0);
    vector<int>order(n+5,0);
    for (int i = 1; i <= n; ++i) {
        int temp;
        cin >> temp;
        pri[temp] = i;
        order[i] = temp;
    }
    if (k>=n) {
        cout << "Yes" << endl;
        return 0;
    }
    vector<queue<int>>sta(k);
    bool flag = 1;
    int leftFront = 1;
    vector<bool>inSta(n+5,0);
    for (int i = 1; i<=n; ++i) {
        if (inSta[order[i]]) {
            bool ha = 0;
            for (auto &t : sta) {
                if (t.empty()) {
                    continue;
                }
                if (t.front() == order[i]) {
                    t.pop();
                    ha = 1;
                    break;
                }
            }
            if (!ha) {
                flag = 0;
                cout << "No" << endl;
                return 0;
            }
        }else{
            while (leftFront<order[i]) {
                int emTrack = -1;
                bool put = 0;
                for (int j = 0; j < k; j++) {
                    if (sta[j].empty()) {
                        emTrack = j;
                    }else if (pri[leftFront] > pri[sta[j].back()]){
                        sta[j].push(leftFront);
                        inSta[leftFront] = 1;
                        put = 1;
                        break;
                    }
                }
                if (!put){
                    if (emTrack == -1) {
                        flag = 0;
                        cout << "No" << endl;
                        return 0;
                    }else{
                        sta[emTrack].push(leftFront);
                        inSta[leftFront] = 1;
                    }
                }
                leftFront++;
            }
            bool flaa = 1;
            for (auto &f : sta) {
                if (f.empty()) {
                    flaa = 0;
                    leftFront++;
                    break;
                }
            }
            if (flaa) {
                cout << "No" << endl;
                flag = 0;
                return 0;
            }
        }
    }
    if (flag) {
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }
    return 0;
}
