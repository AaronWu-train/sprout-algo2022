#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <map>
#define ll long long int
#define _ ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
map<char, int>typeint = {{'m',0},{'p',1},{'s',2},{'z',3}};
struct ma{
    int num;
    char type;
    bool tilt = 0;
    bool operator == (const ma &p){
        return (this -> type == p.type)&&(this -> num == p.num);
    }
};

vector <ma> onhand(13);
deque <ma> outhand;

bool cmp(ma a, ma b){
    if (a.type == b.type){
        return a.num < b.num;
    }else{
        return typeint[a.type] < typeint[b.type];
    }
}
void myremove(ma k){
    auto it = find(onhand.begin(), onhand.end(),k);
    onhand.erase(it);
    return;
}
ma mkma(string a,bool k = 0){
    ma b;
    b.num = a[0]-'0';
    b.type = a[1];
    b.tilt = k;
    return b;
}
void print(){
    vector<char>firstly;
    vector<char>secondly;
    for(ma i : onhand){
        if(!i.tilt){
            firstly.push_back('0'+i.num);
            secondly.push_back(i.type);
        }
    }
    for(ma i : outhand){
        if(i.tilt == 0){
            firstly.push_back('0'+i.num);
            secondly.push_back(i.type);
        }else{
            firstly.push_back('.');
            firstly.push_back('.');
            secondly.push_back('0'+i.num);
            secondly.push_back(i.type);
        }
    }
    for(auto cur : firstly){
        cout << cur;
    }
    cout << "\n";
    for(auto cur : secondly){
        cout << cur;
    }
    cout << "\n";
    return;
}

void insert(){
    string tema,temb,temc;
    cin >> tema >> temb >> temc;
    ma c2 = mkma(temc);
    for (int i = 0; i < onhand.size(); i++) {
        if (c2 == onhand[i]){
            onhand[i] = mkma(tema);
            break;
        }
    }
    return;
}
void chi(){
    string st1,st2,st3,st4,xx1,xx2,xx3;
    cin >> st1 >> xx1 >> st2 >> xx2 >> st3 >> xx3 >> st4;
    ma c1 = mkma(st1,1);
    ma c2 = mkma(st2);
    ma c3 = mkma(st3);
    ma c4 = mkma(st4);
    if (cmp(c2,c3)) {
        outhand.push_front(c3);
        outhand.push_front(c2);
        outhand.push_front(c1);

    }else{
        outhand.push_front(c2);
        outhand.push_front(c3);
        outhand.push_front(c1);
    }
    myremove(c2);
    myremove(c3);
    myremove(c4);
    return;
}
void pon(){
    string st1,st2,st3,xx1,xx2;
    cin >> st1 >> xx1 >> st2 >> xx2 >> st3;
    ma c1 = mkma(st1,1);
    ma c11 = mkma(st1);
    ma c2 = mkma(st3);
    if (st2 == "left") {
        outhand.push_front(c11);
        outhand.push_front(c11);
        outhand.push_front(c1);
    }else if (st2 == "opposite") {
        outhand.push_front(c11);
        outhand.push_front(c1);
        outhand.push_front(c11);
    }else if (st2 == "right") {
        outhand.push_front(c1);
        outhand.push_front(c11);
        outhand.push_front(c11);
    }
    myremove(c11);
    myremove(c11);
    myremove(c2);
    return;
}
int main(){_
    int t;
    cin >> t;
    while (t--) {
        onhand.resize(13);
        outhand.clear();
        for (int i = 0; i < 13; ++i) {
            string temp;
            cin >> temp;
            onhand[i] = mkma(temp);
        }
        int n;
        cin >> n;
        sort(onhand.begin(), onhand.end(), cmp);
        print();
        for (int i = 0; i < n; ++i) {
            string mode;
            cin >> mode;
            if (mode == "insert") {
                insert();
            }else if(mode == "pon"){
                pon();
            }else if(mode == "chi"){
                chi();
            }
            sort(onhand.begin(), onhand.end(), cmp);
            print();
        }
    }
    return 0;
}
