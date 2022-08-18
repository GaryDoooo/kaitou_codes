#include <iostream>
using namespace std;
int a, b;
int main() {
    cin >> a >> b;
    for (int i = a; i <= b; i++) {
        if (i % 7 == 0 or i % 10 == 7)
            cout << "pass" << endl;
        else
            cout << i << endl;
    }
}
