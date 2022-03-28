#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <bitset>
#define All(x) begin(x),end(x)
#define ll long long int
#ifndef onlinejudge
    #define debug(x) cout<<#x<<" = "<<(x)<<endl
#else
    #define debug(x)
#endif
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

inline void swap (int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void selection_sort(int p[],int oringinal_size){
    int max_thing = p[0];
    int max_thing_pos = 0;
    int n = oringinal_size;
    while(n>0) {
        max_thing = p[0];
        max_thing_pos = 0;
        for (int i = 0; i < n; ++i)
        {
            if (max_thing<p[i])
            {
                max_thing = p[i];
                max_thing_pos = i;
            }
        }
        swap(p[n-1],p[max_thing_pos]);
        n--;
    }
}

int main() {_
    int arr[] = {3,4,2,6,5,1};
    for(auto& i : arr) {
        cout << i << ' ';
    }
    cout << endl;
    selection_sort(arr,6);
    for(auto& i : arr) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}
