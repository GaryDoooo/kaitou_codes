#include <stdio.h>
using namespace std;
int main() {
    int r;
    scanf("%d", &r);
    double area = 3.1419526 * r * r;
    double prem = area / r * 2;
    printf("%0.2f\n%0.2f\n", area, prem);
}
