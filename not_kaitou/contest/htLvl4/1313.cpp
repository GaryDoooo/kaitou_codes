#include <iostream>
using namespace std;
int main() {
    string i;
    cin >> i;
    string j(i.rbegin(), i.rend());
    if (i != j) {
        cout << "No" << endl;
        return 0;
    }
    int n = stoi(i);
    for (int k = 2; k < n; k++) {
        if (n % k == 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
