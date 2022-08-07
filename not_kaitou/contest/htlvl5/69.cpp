#include <iostream>
using namespace std;
void print(char c, int count) {
    for (int i = 0; i < count; i++) cout << c;
}
int main() {
    int n;
    cin >> n;
    int base = n * 2 - 1;
    for (int i = 1; i <= base; i += 2) {
        print(' ', (base - i) / 2);
        print('*', i);
        cout << endl;
    }
}
