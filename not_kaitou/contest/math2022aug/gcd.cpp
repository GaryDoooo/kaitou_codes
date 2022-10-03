#include <iostream>
using namespace std;
int main() {
    unsigned long long k, z, x, y;
    cin >> z >> k;
    cout << z + (k / z + (k % z != 0)) * z << endl;
}
