#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    if (n >= 86) {
        cout << "VERY GOOD" << endl;
    } else if (n >= 60) {
        cout << "GOOD";
    } else {
        cout << "BAD" << endl;
    }
}
