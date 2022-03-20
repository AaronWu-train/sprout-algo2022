#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(){
    int t;
    cin >> t;
    priority_queue<int,vector<int>,greater<int>>pq;
    while(t--){
        int a;
        cin >> a;
        if(a==1){
            int temp;
            cin >> temp;
            pq.push(temp);
        }else{
            if(pq.empty()){
                cout << "empty!\n";
            }else{
                cout << pq.top() << endl;
                pq.pop();
            }
        }
    }
}
