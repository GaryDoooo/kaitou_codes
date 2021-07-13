#include <iostream>
#include <vector>
using namespace std;

vector<int> convert_to_base(long long n, int base) {
    vector <int> res;
    while (n > 1) {
        res.push_back(n % base);
        n /= base;
    }
    return res;
}
bool hui_vecn(vector<int> n) {
}
int main() {
    long long x;
    cin >> x;
}