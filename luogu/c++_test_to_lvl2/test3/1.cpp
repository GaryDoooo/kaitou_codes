#include <iostream>
#include <string>
using namespace std;

int main() {
    string n;
    cin >> n;
    if (n.find("4") != string::npos or n.find("13") != string::npos) {
        cout << "NOOO!";
    } else cout << "YESS!";
}