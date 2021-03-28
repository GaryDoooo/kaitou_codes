#include <iostream>
using namespace std;

int main() {
    int a[25];
    for (int i = 0; i < 25; i++) cin >> a[i];
    for (int row = 0; row < 5; row++) {
        int start_index = row * 5;
        int max = a[start_index], max_x = 0;
        for (int i = 0; i < 5; i++)
            if (a[i + start_index] > max) {
                max   = a[i + start_index];
                max_x = i;
            }
        start_index = max_x;
        int min = a[start_index], min_y = 0;
        for (int i = 0; i < 25; i += 5)
            if (a[i + start_index] < min) {
                min   = a[i + start_index];
                min_y = i / 5;
            }
        if (min == max) {
            cout << min_y + 1 << " " << max_x + 1 << " " << max << endl;
            return 0;
        }
    }
    cout << "not found" << endl;
    return 0;
}
