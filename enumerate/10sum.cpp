#include <iostream>
using namespace std;
int main() {
    int ans = 0;
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
            if (i + j > 10)
                ans++;
    cout << ans << endl;
}