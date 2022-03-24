#include <vector>
#include <iostream>
#include <bitset>

using namespace std;

bitset<1500>tried[1500];
bitset<1500>inArea;
int areasize = 0;
int areaasked[1500];
int k;
void initialize(int n) {
    k = n;
}

int hasEdge(int a, int b) {
    if (areasize==0) {
        inArea[a]=1;
        inArea[b]=1;
        areasize = 2;
        return 1;
    }
    if ( (!inArea[a]) && (!inArea[b]) ) {
        tried[a][b]=1;
        tried[b][a]=1;
        return 0;
    }
    if (inArea[a]) {
        areaasked[b]++;
        if (areaasked[b]>=areasize) {
            for (int i = 0; i <= k; ++i) {
                areaasked[i]+=(int)tried[b][i];
            }
            areasize++;
            inArea[b]=1;
//            tried[a][b]=1;
//            tried[b][a]=1;
            return 1;
        } else {
//            tried[a][b]=1;
//            tried[b][a]=1;
            return 0;
        }
    } else if (inArea[b]) {
        areaasked[a]++;
        if (areaasked[a]>=areasize) {
            for (int i = 0; i <=k; ++i) {
                areaasked[i]+=(int)tried[a][i];
            }
            areasize++;
            inArea[a]=1;
//            tried[a][b]=1;
//            tried[b][a]=1;
            return 1;
        } else {
//            tried[a][b]=1;
//            tried[b][a]=1;
            return 0;
        }
    }
    else return 0;
}

//
//
//int main(){
//    cin >> k;
//    initialize(k);
//    for (int i = 1;i<=k*(k-1)/2;++i ){
//        int a,b;
//        cout << "time:" << i << endl;
//        cin >> a >> b;
//        cout << hasEdge(a, b)<<endl;
//    }
//}
