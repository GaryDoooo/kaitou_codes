#include <stdio.h>
using namespace std;
int main() {
    unsigned int r, g, b;
    scanf("%d %d %d", &r, &g, &b);
    printf("#%02X%02X%02X", r, g, b);
    return 0;
}