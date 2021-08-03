#include <bits/stdc++.h>
using namespace std;
int main()
{
    int w, h;
    cin >> h >> w;
    vector<vector<char>> v = {};
    for (int i = 0; i < h; i++)
    {
        vector<char> temp = {};
        for (int j = 0; j < w; j++)
        {
            char e;
            cin >> e;
            temp.push_back(e);
        }
        v.push_back(temp);
    }
    string s;
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            if (v[y][x] != '*')
            {
                s = "";
                if (x - 1 >= 0)
                {
                    s += v[y][x - 1];
                }
                if (x + 1 < w)
                {
                    s += v[y][x + 1];
                }
                if (y - 1 >= 0)
                {
                    s += v[y - 1][x];
                    if (x - 1 >= 0)
                    {
                        s += v[y - 1][x - 1];
                    }
                    if (x + 1 < w)
                    {
                        s += v[y - 1][x + 1];
                    }
                }

                if (y + 1 < h)
                {
                    s += v[y + 1][x];
                    if (x - 1 >= 0)
                        s += v[y + 1][x - 1];
                    if (x + 1 < w)
                    {
                        s += v[y + 1][x + 1];
                    }
                }
                cout << count(s.begin(), s.end(), '*');
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }
    return 0;
}
// for y in range(self.height):
//             for x in range(self.width):
//                 surrounding = ""
// #to the left
//                 if x - 1 >= 0:
//                     surrounding += str(s[y][x - 1])
// #to the right
//                 if x + 1 < self.width:
//                     surrounding += str(s[y][x + 1])
// #below
//                 if -1 < y - 1:
//                     surrounding += str(s[y - 1][x])
// #lower left corner
//                     if x - 1 >= 0:
//                         surrounding += str(s[y - 1][x - 1])
// #lower right corner
//                     if x + 1 < self.width - 1:
//                         surrounding += str(s[y - 1][x + 1])
// #above
//                 if y + 1 < self.height:
//                     surrounding += str(s[y + 1][x])
// #upper left corner
//                     if x - 1 >= 0:
//                         surrounding += str(s[y + 1][x - 1])
// #upper right corner
//                     if x + 1 < self.width:
//                         surrounding += str(s[y + 1][x + 1])
// #Update the cell number
//                 s[y][x].set_num(surrounding.count("*"))