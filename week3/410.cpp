#include <random>
#include <chrono>
#include <vector>
#include <iostream>
#include <map>
#define debug(x) cerr<<#x<<" = "<<(x)<<endl

using namespace std;
//auto seed = std::chrono::steady_clock::now().time_since_epoch().count();
//std::mt19937 rng(seed);

struct area{
    int num = 1;
    map<short, int>link;
    bool trash = 0;
};
vector<area>arr;
vector<short>father;
int k;
void initialize(int n){
    k = n;
    arr.resize(n);
    father.resize(n);
    for (int i = 0; i < n; ++i) {
        father[i]=i;
    }
}

int hasEdge(int a, int b){
    arr[father[a]].link[father[b]]+=1;
    arr[father[b]].link[father[a]]+=1;
    if (arr[father[a]].link[father[b]]<arr[father[a]].num*arr[father[b]].num) {
//        debug(arr[father[a]].link[father[b]]);
        return 0;
    }else{
        arr[father[a]].num+=arr[father[b]].num;
//        debug(arr[father[a]].num);
        for (int i = 0; i < k; ++i) {
            arr[father[a]].link[i]+=arr[father[b]].link[i];
        }
        arr[father[b]].link.clear();
        arr[father[b]].trash = 1;
        for (int i = 0; i < k; ++i) {
            if (!arr[i].trash&&i!=father[a]) {
                arr[i].link[father[a]]+=arr[i].link[father[b]];
                arr[i].link.erase(father[b]);
            }
        }
        father[b]=father[a];
        return 1;
    }
}
int main(){
    cin >> k;
    initialize(k);
    for(int i = 1;i<=k*(k-1)/2;++i ){
        int a,b;
        cout << "time:" << i << endl;
        cin >> a >> b;
        cout << hasEdge(a, b)<<endl;
    }
}
