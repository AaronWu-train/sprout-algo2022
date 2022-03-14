#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <bitset>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int n;

int dfs(int i, vector<vector<int>> &graph, vector<int>&terrible, bitset<100005> &visited){
    visited[i] = true;
    int maxnum = 0;
    int cur_sum = 0;
    for (auto& child : graph[i]) {
        if (!visited[child]) {
            int cur_chlid_size = dfs(child, graph, terrible, visited);
            cur_sum+=cur_chlid_size;
            maxnum=max(maxnum, cur_chlid_size);
        }
    }
    cur_sum++;
    terrible[i] = max(maxnum, n-cur_sum);
    return cur_sum;
}

int main() {_
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<vector<int>>graph(n+5);
        for (int i = 0; i < n-1; ++i) {
            int node1,node2;
            cin >> node1 >> node2 ;
            graph[node2].push_back(node1);
            graph[node1].push_back(node2);
        }
        vector<int>terrible(n+5,0);
        bitset<100005>visited = 0;
        dfs(0, graph, terrible, visited);
        int min_ter_index = 0;
        for (int i = 1; i < n; ++i) {
            if (terrible[i]<terrible[min_ter_index]) {
                min_ter_index = i;
            }
        }
        cout << min_ter_index << '\n';
    }
    
    
    
    
    return 0;
}
