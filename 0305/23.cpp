#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <climits>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
void push_train();
void move_station_1_to_2();
void move_station_2_to_1();
void pop_train();


void solve(int N,int order[]){
    vector<int>place(N+5,0);
    queue<int>n0;
    stack<int>n1;
    stack<int>n2;
    for (int i = 1; i <= N; i++) {
        n0.push(i);
    }
    for (int i = 0; i < N; i++) {
        while(place[order[i]] != 3){
            while (place[order[i]] == 0) {
                push_train();
                n1.push(n0.front());
                place[n0.front()] = 1;
                n0.pop();
            }
            while (place[order[i]] == 1) {
                move_station_1_to_2();
                n2.push(n1.top());
                place[n1.top()] = 2;
                n1.pop();
            }
            while (place[order[i]] == 2 && n2.top()!=order[i]) {
                move_station_2_to_1();
                n1.push(n2.top());
                place[n2.top()] = 1;
                n2.pop();
            }
            if (n2.top()==order[i]) {
                pop_train();
                place[order[i]]=3;
                n2.pop();
            }
        }
    }
    
}




int main() {_
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    solve(n, a);
    
    return 0;
}

void push_train(){
    cout << "push_train" << endl;
}
void move_station_1_to_2(){
    cout << "move_station_1_to_2" << endl;
}
void move_station_2_to_1(){
    cout << "move_station_2_to_2"<<endl;
}
void pop_train(){
    cout <<"pop_train"<<endl;
}
