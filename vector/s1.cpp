#include <iostream>
#include <set>
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

void print_set(set<int> &e, string name) {
    // cout << name << ": {";
    vector<int> v(e.begin(), e.end());
    print_vector(v, name);
}

int main() {
    vector<int> a(5, 4);
    a.insert(a.begin(), 9);
    print_vector(a, "a");
    set<int> b(a.begin(), a.end());
    print_set(b, "b");
    auto it = b.end();
    it--;
    cout << *(b.rbegin()) << endl;
    print_set(b, "b");
}
