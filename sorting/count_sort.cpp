#include <iostream>
#include <vector>
#define vi vector<int>
using namespace std;

vi csort(vi l){
    vi res = {};
    vi book(*max_element(l.begin(),l.end())+1);
    for (int i : l){
        book[i]++;
    }
    for (int i = 0; i < book.size(); i++){
        for (int e = 0; e < book[i]; e++){
            res.push_back(i);
        }
    }
    return res;
}

int main(){
    vi e;
    int a;
    while (cin >> a) e.push_back(a);
    for (int i : csort(e)) cout << i << " ";
}
