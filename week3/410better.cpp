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
    return ++arr[max(a, b)]==max(a,b);
}
