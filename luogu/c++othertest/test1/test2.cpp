#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string res = "";
    int height = 2 * n + 1;
    int width = n + (n - 1);
    int midLine = (height - 3) / 2 + 1;
    for (int i = 0; i < height; i++)
    {
        if (i == 0 or i == height - 1 or i == midLine)
        {
            for (int j = 0; j < width; j++)
                res += "*";
            res += "\n";
        }
        else
        {
            res += "*";
            for (int j = 0; j < width - 1; j++)
                res += " ";
            res += "*\n";
        }
    }
    cout << res;
}