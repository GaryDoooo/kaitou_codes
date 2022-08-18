#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int lvl = 1; lvl <= n; lvl++) {
        for (int i = 0; i < (n - lvl) * 2 + 1; i++) cout << " ";
        for (int i = 0; i < lvl; i++) cout << "/\\  ";
        cout << endl;
        for (int i = 0; i < (n - lvl) * 2; i++) cout << " ";
        for (int i = 0; i < lvl; i++) cout << "/__\\";
        cout << endl;
    }
}
