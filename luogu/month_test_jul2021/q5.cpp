#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bomb_cal(int x, int y, vector<vector<int>> &m)
{
    int grid_count = 1;
    int px = x, py = y;
    //up
    while (1)
    {
        py += 1;

        if (px == m[0].size() or py == m.size())
        {
            break;
        }
        if (m[py][px] == 1)
        {
            break;
        }

        grid_count++;
    }

    px = x;
    py = y;
    //down
    while (1)
    {
        py--;

        if (px == m[0].size() or py == -1)
        {
            break;
        }
        if (m[py][px] == 1)
        {
            break;
        }

        grid_count++;
    }

    px = x;
    py = y;
    //left
    while (1)
    {
        px--;

        if (px == -1 or py == m.size())
        {
            break;
        }
        if (m[py][px] == 1)
        {
            break;
        }

        grid_count++;
    }

    px = x;
    py = y;
    //right
    while (1)
    {
        px++;

        if (px == m[0].size() or py == m.size())
        {
            break;
        }
        if (m[py][px] == 1)
        {
            break;
        }

        grid_count++;
    }

    return grid_count;
}
int main()
{
    int x, y;
    cin >> y >> x;

    vector<vector<int>> v;
    char e;
    for (int i = 0; i < y; i++)
    {
        vector<int> temp;
        for (int j = 0; j < x; j++)
        {
            cin >> e;
            // cout << e << " ";
            if (e == '.')
            {
                temp.push_back(0);
            }
            else
            {
                temp.push_back(1);
            }
        }
        v.push_back(temp);
        // cout << endl;
    }
    // cout << "start One " << endl;
    int max_bombed = -1;
    int b;
    for (int yy = 0; yy < y; yy++)
    {
        for (int xx = 0; xx < x; xx++)
        {
            // cout << "here " << yy << " " << xx << " " << v[yy][xx] << endl;
            if (v[yy][xx] == 0)
            {
                b = bomb_cal(xx, yy, v);
                // cout << b << endl;
                if (b > max_bombed)
                {
                    max_bombed = b;
                }
            }
        }
    }
    cout << max_bombed;
    return 0;
}