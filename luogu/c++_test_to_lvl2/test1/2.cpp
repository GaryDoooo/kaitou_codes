#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n, a = 1, b = 1;
    cin >> n;
    char res[n + 1];
    for (int i = 0; i < n; i++) res[i] = 111;
    res[n] = '\0';
    while (b <= n) {
        res[b - 1] = 79;
        swap(a, b);
        b = a + b;
    }
    cout << res;
    return 0;
}
// char = byte
// string  char[n]; char[last]=0; char* string;
// 
