#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<int> &v, string name) {
    cout << name << ": {";
    for (int i = 0; i < v.size() - 1; i++) {
        cout << v[i] << ", ";
    }
    cout << v.back() << "}"
         << "\n";
}
int main() {
    vector<int> a = {1, 2, 3};
    vector<int> b(a.rbegin(), a.rend());
    vector<int> c(b);
    vector<int> d(a.begin(), a.begin() + 2);
    print_vector(a, "a");
    print_vector(b, "b");
    print_vector(c, "c");
    print_vector(d, "d");
    vector<int> e(a.begin(), a.end());
    // print_vector(e, "e");
    e.insert(e.begin(), 5);
    // print_vector(e, "e");
    e.insert(e.end() - 2, 4, 4);
    // print_vector(e, "e");
    e.insert(e.end(), b.rbegin() + 1, b.rend());
    // print_vector(e, "e");
    e.erase(e.begin());
    print_vector(e, "e");
    e.erase(e.begin() + 1, e.begin() + 4);
    print_vector(e, "e");
    vector<int> f(e);
    f.insert(f.begin(), e.begin() + 1, e.begin() + 3);
    print_vector(f, "f");
    reverse(a.rbegin(), a.rend());
    print_vector(a, "a");
    swap(a[0], a[1]);
    print_vector(a, "a");
}
