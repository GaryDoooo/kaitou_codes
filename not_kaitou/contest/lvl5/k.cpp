#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = n; i >= 1; i--) {
        cout << "**";
        for (int j = 0; j < i; j++) cout << " ";
        for (int j = 0; j < i; j++) cout << "*";
        cout << endl;
    }
    cout << "***" << endl;
    for (int i = 1; i <= n; i++) {
        cout << "**";
        for (int j = 0; j < i; j++) cout << " ";
        for (int j = 0; j < i; j++) cout << "*";
        cout << endl;
    }
}

