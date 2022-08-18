#include <iostream>
using namespace std;
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a * a > b * c)
        cout << "Alice" << endl;
    else
        cout << "Bob" << endl;
}
