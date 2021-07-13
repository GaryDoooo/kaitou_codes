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
bool hui(vector<int> &a) {
    vector<int> r (a.rbegin(), a.rend());
    return (a == r);
}
int main() {
    long long x;
    cin >> x;
    if (convert_to_base(x, ))
    }