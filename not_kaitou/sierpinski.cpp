#include <iostream>
using namespace std;

void draw(char res[100][100], int lvl, int x, int y) {
    if (lvl == 1) {
        res[x][y] = '/';
        res[x + 1][y] = '\\';
        res[x][y + 1] = '_';
        res[x + 1][y + 1] = '_'; //]
        res[x - 1][y + 1] = '/';
        res[x + 2][y + 1] = '\\';
    } else {
        int offset = 1 << (lvl - 1);
        draw(res, lvl - 1, x, y);
        draw(res, lvl - 1, x - offset, y + offset);
        draw(res, lvl - 1, x + offset, y + offset);
    }
}

int main() {
    int n;
    cout << "Input the level of the triangle (1-5): ";
    cin >> n;
    if (n<1 or n>5) {
        cout << "\nOut of range.\n";
        return 0;
    }
    int dim = (1 << n) + 1;
    char res[100][100];
    draw(res, n, dim / 2, 0);
    for (int y = 0; y < dim; y++) {
        for (int x = 0; x < dim * 2; x++)
            if (res[x][y] == '/' or res[x][y] == '\\' or res[x][y] == '_')
                cout << res[x][y];
            else
                cout << " ";
        cout << endl;
    }
    return 0;
}