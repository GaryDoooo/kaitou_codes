#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int w, h;
    cin >> h >> w;
    // cout << "width = " << w << " height = " << h << endl;
    string e;

    for (int i = 0; i < h; i++)
    {
        string temp;
        cin >> temp;

        for (int j = 0; j < w; j++)
        {
            string prev = temp.substr(0, j + 1);
            cout << count(prev.begin(), prev.end(), '#') << " ";
        }
        cout << '\n';
    }
}
