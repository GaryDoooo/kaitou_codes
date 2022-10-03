#include <iostream>
using namespace std;
int N = 10000;
int Q = 10000;
int main() {
    srand(time(NULL));
    cout << N << " " << Q << endl;
    for (int i = 0; i < N; i++) {
        int d = rand() % 100000 + 1;
        int c = rand() % 1000 + 1;
        cout << d << " " << c << endl;
    }
    for (int i = 0; i < Q; i++) {
        int r = rand() % N + 1;
        int v = rand() % 100000 + 1;
        cout << r << " " << v << endl;
    }
}
