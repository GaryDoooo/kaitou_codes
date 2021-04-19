#include <iostream>
#include <vector>
using namespace std;

void printv(vector<int> v){
    for (auto i : v){
        cout << i << " ";
    }
    cout << "\n";
}

int main(){
    vector<int> v = {4,2,5,3,5,8,3};
    printv(v);
    sort(v.begin(),v.end());
    printv(v);
    sort(v.rbegin(),v.rend());
    printv(v);
    string yabetu = "tannjiro";
    cout << yabetu << endl;
    sort(yabetu.begin(), yabetu.end());
    cout << yabetu << endl;
    sort(yabetu.rbegin(), yabetu.rend());
    cout << yabetu << endl;
}