#include <iostream>
using namespace std;
int main() {
    int total = 0;
    int i = 1;
    int day = 0;
    while (1) {
        for (int c = 1; c <= i; c++) {
            total += i;
            day ++;
            if (day == 20) {
                cout << total << endl;
                return 0;
            }
        }
        i ++;
    }
}