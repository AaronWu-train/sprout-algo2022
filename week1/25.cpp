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
    node* prev = NULL;
    int num = 0;
    node(int _num):num(_num){};
    static void merge(node* front, node* back){
        front -> next = back;
        back -> prev = front;
    }
    
};
struct linked_list{
    node* start = new node(0);
    node* end = start;
    int size = 0;
    void push_back(node* a){
        size++;
        node::merge(end, a);
        end = a;
    }
    int pop_front(){
        if (size==0) {
            return -1;
        }
        node* a = start->next;
        if (size==1) {
            start->next = NULL;
            end = start;
        }else{
            node::merge(start, (a->next));
        }
        int i = a->num;
        delete a;
        size--;
        return i;
    }
    
    static void merge_list(linked_list &front, linked_list &back){
        node::merge(front.end, (back.start->next));
        front.size+=back.size;
        back.size=0;
        
        front.end = back.end;
        back.end = back.start;
        
        back.start->next=NULL;
        return;
    }
    static void print(linked_list&li){
        auto cur = li.start;
        while (cur!=li.end) {
            cur = cur->next;
            cout << " " << cur->num;
        }
    }
};
int main() {_
    int n,m;
    cin >> n >> m;
    vector<linked_list>arr(n+5);
    for (int h = 0; h < m; h++) {
        string type;
        cin >> type;
        if (type[0]=='A') {
            int i,id;
            cin >> i >> id;
            auto tem = new node(i);
            arr[i].push_back(tem);
        }else if(type[0]=='L'){
            int i;
            cin >> i;
            int ttt = arr[i].pop_front();
            if (ttt==-1) {
                printf("queue %d is empty!\n",i);
            }
        }else if(type[0]=='J'){
            int i,j;
            cin >> i >> j;
            linked_list::merge_list(arr[j], arr[i]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        auto& ls = arr[i];
        if (ls.size==0) {
            printf("queue %d: empty\n",i);
        }else{
            printf("queue %d:",i);
            linked_list::print(ls);
            cout << endl;
            
        }
    }
    
    
    
    
    return 0;
}
