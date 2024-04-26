#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <bitset>
#define All(x) begin(x),end(x)
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int n;
vector<double>a;
vector<double>b;
vector<double>c;
void init();
void solve();
double happinese(double);

int main() {
    int t;
    cin >> t;
    while (t--) {
        init();
        solve();
    }
    return 0;
}

void init(){
    cin >> n;
    a.clear();
    b.clear();
    c.clear();
    a.resize(n);
    b.resize(n);
    c.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }
    return;
}

void solve(){
    double l = 0;
    double r = 300;
    while (r - l > 1e-8) {
        double midl = l + (r-l)/3;
        double midr = l + 2*(r-l)/3;
//        debug(l);debug(midl);debug(midr);debug(r);
        if (happinese(midl) < happinese(midr)) {
            r = midr;
//            cerr << "debug : r" << endl;
        } else {
            l = midl;
//            cerr << "debug : l" << endl;
        }
    }
    printf("%.10f\n",happinese(l));
}

double happinese(double time){
    double maxnum = INT_MIN;
    for (int i = 0; i < n; ++i) {
        maxnum = max(maxnum, ( a[i]*(time-b[i])*(time-b[i]) + c[i] ));
    }
//    debug(time);
//    printf("debug : maxnum = %.8f\n",maxnum);
    return maxnum;
}
