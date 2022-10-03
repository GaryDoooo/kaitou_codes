#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin >> n;
    while (n % 5 == 0) n /= 5;
    while (n % 3 == 0) n /= 3;
    while (n % 2 == 0) n /= 2;
    if (n == 1)
        printf("Regular Number\n");
    else
        printf("Irregular Number");
}

