#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<pair<int, int>> a{{1, 2}, {3, 4}};
    auto it = a.begin();
    cout << it->first << endl;
    cout << (*it).first << endl;
}