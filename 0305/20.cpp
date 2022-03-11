#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <climits>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

struct node{
    int num;
    node* next;
    node* prev;
};


int main() {_
    int t;
    cin >> t;
    for (int count = 1; count <= t; count++) {
        cout << "Line #"<<count<<endl;
        int n;
        cin >> n;
        vector<int>which_group(1000005,0);
        for (int i = 1; i <= n; i++) {
            int temp;
            cin >> temp;
            for (int j = 0; j < temp; j++) {
                int tem2;
                cin >> tem2;
                which_group[tem2]=i;
            }
        }
        int m;
        cin >> m;
        node empty;
        node* curFront = &empty;
        node* curLast = &empty;
//        node nodestore[100000];
        vector<node*>where_is_group(n+5,&empty);
//        int where_can_use = 0;
        while (m--) {
            string type;
            cin >> type;
//            debug(type);
            if (type[0]=='E') {
                int who;
                cin >> who;
//                nodestore[where_can_use].num=who;
                node* newnode = new node;
                newnode->num=who;
                if (curFront == &empty) {    //進空隊伍
                    curFront = newnode;
                    curLast = newnode;
                    newnode-> next=&empty;
                    if (which_group[who]!=0) {
                        where_is_group[which_group[who]] = newnode;
                    }
                }else if(which_group[who]==0||where_is_group[which_group[who]]==&empty){//排隊
                    newnode -> prev = curLast;
                    curLast -> next = newnode;
                    curLast = newnode;
                    newnode -> next = &empty;
                    if (which_group[who]!=0) {
                        where_is_group[which_group[who]]=newnode;
                    }
                }else{ //插隊
                    newnode->prev = where_is_group[which_group[who]];
                    newnode->next = (where_is_group[which_group[who]] -> next);
                    where_is_group[which_group[who]] -> next -> prev = newnode;
                    where_is_group[which_group[who]] -> next = newnode;
                    where_is_group[which_group[who]] = newnode;
                    if (newnode->next==&empty) {
                        curLast = newnode;
                    }
                }
//                where_can_use++;
            }else{
                cout << curFront->num << endl;
//                if (m!=0||count!=0) {
//                    cout << endl;
//                }
                node* torelease = curFront;
                curFront = curFront->next;
//                debug(curFront->next->num);
                delete torelease;
            }
        }
        
    }
    return 0;
}
