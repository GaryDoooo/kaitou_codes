#include <iostream>
using namespace std;
int main() {
    int total = 0;
    int i = 1;
    int day = 1;
    while (1) {
        for (int c = 1; c <= i; c++) {
            total += i;
            day ++;
            if (day == 20) break;
        }
        i ++;
    }
    cout << total << endl;
}