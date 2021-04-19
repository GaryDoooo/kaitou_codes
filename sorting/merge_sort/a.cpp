#include <iostream>
#include <vector>
#define V vector<int>
#define I vector<int>::iterator
using namespace std;

void merge_sort(I start, I end) {
    if (end == start + 1) return;
    I mid = start + (end - start) / 2;
    V left(start, mid);
    V right(mid, end);
    I i = start, ri = right.begin(), li = left.begin();
    merge_sort(left.begin(), left.end());
    merge_sort(right.begin(), right.end());
    while (i != end) {
//        if (li >= left.end())
//            *i++ = *ri++;
//        else if (ri >= right.end())
//            *i++ = *li++;
//        else if (*ri < *li)
        if (*ri < *li or li >=left.end())
            *i++ = *ri++;
        else
            *i++ = *li++;
    }
}

int main() {
    V a;
    int i;
    while (cin >> i) a.push_back(i);
    merge_sort(a.begin(), a.end());
    for (auto j : a) cout << j << " ";
}
