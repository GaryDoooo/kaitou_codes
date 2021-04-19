#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    string res = "";
    vector<int> fib = {1, 1};
    for (int i = 0; i < 1000; i ++) {
        fib.push_back(fib.back() + * (fib.end() - 2));
    }
    for (int i = 1; i <= n; i++) {
        if (find(fib.begin(), fib.end(), i) != fib.end()) res += "O";
        else res += "o";
    }
    cout << res;
}
