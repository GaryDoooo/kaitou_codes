#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vector(vector<int> &list) {
    for (auto i : list) cout << i << " ";
    cout << endl;
}

int main() {
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    print_vector(v);
    swap(v[1], v[3]);
    print_vector(v);
    // sort(v.rbegin(), v.rend());
    cout << "end -2 v[-2] " << *(v.end() - 2) << " " << v[v.size() - 2] << endl;
    cout << "rend -2 " << *(v.rend() - 2) << endl;
    cout << "v[-1] " << v.back() << endl;
    cout << "v[0] " << v.front() << endl;
    for (auto i = v.rbegin(); i != v.rend(); ++i) cout << *i << " ";
    cout << endl;
    v.erase(v.begin(), v.end() - 4);
    print_vector(v);
    v.pop_back();
    print_vector(v);
    v.push_back(2);
    print_vector(v);
    v.insert(v.begin() + 2, v.begin() + 1, v.end() - 1);
    print_vector(v);
    reverse(v.begin(), v.end());
    print_vector(v);
    int *p = v.data();
    cout << *p << " " << *(p + 2) << " " << p[3] << " " << *(p + 1) << endl;
    vector<int> v2(v);
    print_vector(v2);
    vector<int> v3(v.begin() + 1, v.end() - 2);
    print_vector(v3);
    vector<int> v4(v.rbegin(), v.rend());
    print_vector(v4);
}