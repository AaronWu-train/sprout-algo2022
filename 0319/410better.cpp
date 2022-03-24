#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

vector<int>arr;
void initialize(int n) {
    arr.resize(n,0);
    arr.clear();
}

int hasEdge(int a, int b) {
    int temp = max(a, b);
    arr[temp]++;
    if (arr[temp]==temp) {
        return 1;
    }else{
        return 0;
    }
}
