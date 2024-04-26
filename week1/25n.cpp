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
    node* next = NULL;
    int num = 0;
    node(int _num):num(_num){};
    
};
struct linked_list{
    node* start = new node(0);
    node* end = start;
    
};
int main() {_
    int n,m;
    cin >> n >> m;
    vector<linked_list>arr(n+5);
    for (int h = 0; h < m; h++) {
        // for (int i = 1; i <= n; ++i) {
        //     auto& ls = arr[i];
        //     if (ls.start->next==NULL) {
        //       printf("queue %d: empty\n",i);
        //     }else{
        //         printf("queue %d:",i);
        //         auto cur = ls.start->next;
        //         while (cur!=NULL) {
        //             cout << " " << cur->num;
        //             cur = cur->next;
        //         }
        //         cout << endl;
        //     }
        // }
        string type;
        cin >> type;
        if (type[0]=='A') {
            int i,id;
            cin >> i >> id;
            auto temp = new node(id);
            arr[i].end->next=temp;
            arr[i].end = temp;
        }else if(type[0]=='L'){
            int i;
            cin >> i;
            auto temp = arr[i].start->next;
            if (!temp) {
                cout << "queue "<<i<<" is empty!\n";
//                printf("queue %d is empty!\n",i);
            }else{
                if (temp->next == NULL) {
                    arr[i].end=arr[i].start;
                    arr[i].start->next=NULL;
                    continue;
                }
                arr[i].start->next = temp->next;
                delete temp;
            }
        }else if(type[0]=='J'){
            int i,j;
            cin >> i >> j;
            auto tem1 = arr[i].start -> next;
            if (tem1==NULL||i==j) {
                continue;
            }
            arr[j].end->next=tem1;
            arr[j].end = arr[i].end;
            arr[i].start->next = NULL;
            arr[i].end = arr[i].start;
        }
        
    }
    for (int i = 1; i <= n; ++i) {
        auto& ls = arr[i];
        if (ls.start->next==NULL) {
            cout << "queue " << i << ": empty\n";
//           printf("queue %d: empty\n",i);
        }else{
//            printf("queue %d:",i);
            cout << "queue " << i <<":";
            auto cur = ls.start->next;
            while (cur!=NULL) {
                cout << " " << cur->num;
                cur = cur->next;
            }
            cout << endl;
        }
    }
    
    
    
    
    return 0;
}
