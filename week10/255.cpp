#include <bits/stdc++.h>
using namespace std;
typedef __int128 ll; typedef pair<int, int> pii;
#define AI(x) begin(x),end(x)
#define ff first
#define ss second
#ifdef DEBUG
#define debug(args...) LKJ("[ "+string(#args)+" ]", args)
template<class I> void LKJ(I&&x){ cerr << x << '\n'; }
template<class I, class...T> void LKJ(I&&x, T&&...t){ cerr << x << ", ", LKJ(t...); }
template<class I> void OI(I a, I b){ while(a < b) cerr << *a << " \n"[next(a) == b], ++a; }
#else
#define debug(...) 0
#define OI(...) 0
#endif
struct func{
    ll a;
    ll b;
    ll pre;
};

func coeff( __int128 x1, __int128 y1, __int128 x2, __int128 y2) {
    func ret;
    ret.a = 1ll*x2*y1-1ll*x1*y2;
    ret.pre = 1ll*x1*x2*(x1-x2);
    ret.b = (1ll*y1*(x2*(x1-x2))) - ((1LL*x1*x2*y1)-(1LL*x1*x1*y2));
    return ret;
}
int n;

int solve(ll s, vector<int>&dp, vector<pair<__int128,__int128>>&pig){
//    debug(s);
	if(dp[s]!=-1) return dp[s];
    if(s==0)return 0;
	if((s&-s) == s) return 1;
	ll l = 0;
//    debug(s&-s);
    while (!((1<<l)&(s&-s)) ){
        l++;
    }
    int minn = 1e9;
	for (ll i = l+1; i < n; ++i){
       if ( (s>>i)&1 ) {
           auto re = coeff(pig[l].ff, pig[l].ss, pig[i].ff, pig[i].ss);
           if ((__int128)1*re.a*re.pre<0) {
               ll mask = s - (1ll<<i) -(s&-s);
               for (__int128 j = i+1; j < n; j++) {
                   if ((1<<j)&s && re.a*pig[j].ff*pig[j].ff + re.b*pig[j].ff == pig[j].ss*re.pre) {
                        mask-=1ll<<j;
                   }
               }
//               debug(minn);
               minn = min(minn, solve(mask,dp,pig)+1);
           }
       }
	}
    minn = min(minn,solve((s-(s&-s)),dp,pig)+1);

    dp[s] = minn;
    return minn;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<pair<__int128,__int128>> pig;
		for (int i = 0; i < n; ++i) {
			int x,y;
			cin >> x >> y;
			pig.push_back(make_pair(x,y));
		}
        vector<int>dp((1<<n)+5,-1);
        cout << solve((1ll<<n)-1,dp,pig) << endl;
	}

	return 0;
}


