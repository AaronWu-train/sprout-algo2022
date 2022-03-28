#include <iostream>
#include <string>
using namespace std;
int main() {
    string a,b;
    int times[26] = {0};
    cin >> a >> b;
    for(int i = 0; i < a.size(); ++i){
        times[(a[i]-'a'+b[i]-'a')%26]++;
    }
    for(int i = 0; i < 25 ;++i){
        cout << times[i] << " ";
    }
    
    cout << times[25];
}