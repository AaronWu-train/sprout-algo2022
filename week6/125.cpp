#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <bitset>
#define All(x) begin(x),end(x)
#define ll long long int
#define endl '\n'
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int mod = 10000019;
inline ll madd(ll a, ll b){
    return ((a+b)%mod+mod)%mod;
}

ll mergeSort(vector<ll> &arr, int l, int r){
    if (l==r) {
        return 0;
    }
    int mid = l + (r-l)/2;
    ll ans = 0;
    ans = madd(ans, mergeSort(arr,l,mid));
    ans = madd(ans, mergeSort(arr, mid+1, r));
    int ri = mid+1;
    ll tempans = 0;
    for (int li = l; li <= mid; li++) {
        while (ri <= r && arr[ri]<arr[li]) {
            tempans = madd(tempans, arr[ri]);
            ri++;
        }
        ans = madd(tempans, ans);
        ans = madd(arr[li]*(ri-mid-1)%mod, ans);
    }
    
    int li = l;
    ri = mid+1;
    vector<ll>sorted;
    while (sorted.size()<=r-l) {
        if (li>mid) {
            sorted.push_back(arr[ri]);
            ri++;
            continue;
        }
        if (ri>r) {
            sorted.push_back(arr[li]);
            li++;
            continue;
        }
        if (arr[li]>arr[ri]) {
            sorted.push_back(arr[ri]);
            ri++;
            continue;
        }else{
            sorted.push_back(arr[li]);
            li++;
            continue;
        }
    }
    auto k = sorted.begin();
    for (int i = l; i <= r; ++i) {
        arr[i] = *k;
        k++;
    }
    return ans;

}

signed main() {_
    int n;
    cin >> n;
    vector<ll>arr(n);
    for(ll &i:arr)cin >> i;
    cout << mergeSort(arr, 0, n-1) << endl;
    return 0;
}
