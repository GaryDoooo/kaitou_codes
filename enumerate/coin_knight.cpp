#include <iostream>
using namespace std;
int main() {
    int total = 0;
    int i = 1;
    int day = 1;
    while (day <= 20) {
        for (int c = 1; c <= i; c++) {
            total += i;
            day ++;
        }
        i ++;
    }
}