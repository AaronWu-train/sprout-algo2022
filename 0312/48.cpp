#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
struct node{
    int num;
    int left = -1;
    int right = -1;
};
vector<node>arr;

void add(int n){
    if (arr.empty()) {
        node temp;
        temp.num=n;
        arr.push_back(temp);
    }else{
        int i = 0;
        while (1) {
            if (n>arr[i].num) {
                if (arr[i].right==-1) {
                    node temp;
                    temp.num=n;
                    arr.push_back(temp);
                    arr[i].right = (int)arr.size()-1;
                    return;
                }else{
                    i = arr[i].right;
                }
            }else{
                if (arr[i].left==-1) {
                    node temp;
                    temp.num=n;
                    arr.push_back(temp);
                    arr[i].left = (int)arr.size()-1;
                    return;
                }else{
                    i = arr[i].left;
                }
            }
        }
    }
}
void dfs(int index){
    if (arr[index].left!=-1) {
        dfs(arr[index].left);
    }
    if (arr[index].right!=-1) {
        dfs(arr[index].right);
    }
    cout << arr[index].num << '\n';
}
int main() {_
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int tem;
        cin >> tem;
        add(tem);
    }
    dfs(0);
    return 0;
}
