#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<vector<int>> combos = {{1, 2, 3, 4}, {1, 2, 4, 3}, {1, 3, 2, 4}, {1, 3, 4, 2}, {1, 4, 2, 3}, {1, 4, 3, 2}, {2, 1, 3, 4}, {2, 1, 4, 3}, {2, 3, 1, 4}, {2, 3, 4, 1}, {2, 4, 1, 3}, {2, 4, 3, 1}, {3, 1, 2, 4}, {3, 1, 4, 2}, {3, 2, 1, 4}, {3, 2, 4, 1}, {3, 4, 1, 2}, {3, 4, 2, 1}, {4, 1, 2, 3}, {4, 1, 3, 2}, {4, 2, 1, 3}, {4, 2, 3, 1}, {4, 3, 1, 2}, {4, 3, 2, 1}};
vector<int> skyscrapers_seen = {4, 3, 3, 3, 2, 2, 3, 2, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1};

bool valid(vector<vector<int>> a)
{
    for (int i = 0; i < 4; i++)
    {
        vector<int> e = {1, 2, 3, 4};
        sort(a[i].begin(), a[i].end());
        if (a[i] != e)
            return false;
    }
    int r90[4][4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            r90[j][i] = a[i][j];
        }
    }

    return true;
}

int **SolvePuzzle(int *clues)
{
    int res[4][4];
    vector<int> skyscraper_num(clues.begin(), clues.begin() + 4);
    vector<int> for_times(4);
    for (int i = 0; i < 4; i++)
    {
        switch (skyscraper_num[i])
        {
        case 0:
            for_times[i] = 24;
            break;
        case 1:
            for_times[i] = 6;
            break;
        case 2:
            for_times[i] = 11;
            break;
        case 3:
            for_times[i] = 6;
            break;
        case 4:
            for_times[i] = 1;
            break;
        default:
            break;
        }
    }
    for (int c1 = 0; c1 < for_times[0]; c1++)
    {
        for (int c2 = 0; c2 < for_times[1]; c2++)
        {
            for (int c3 = 0; c3 < for_times[2]; c3++)
            {
                for (int c4 = 0; c4 < for_times[3]; c4++)
                {
                                }
            }
        }
    }
}

bool equal(int **puzzle, int expected[4][4])
{
    if (!puzzle || !expected)
        return 0;
    for (int i = 0; i < 4; ++i)
        if (memcmp(puzzle[i], expected[i], 4 * sizeof(int)))
            return 0;
    return 1;
}

int main()
{
    // static int clues[][16] = {
    //     {2, 2, 1, 3,
    //      2, 2, 3, 1,
    //      1, 2, 2, 3,
    //      3, 2, 1, 3},
    //     {0, 0, 1, 2,
    //      0, 2, 0, 0,
    //      0, 3, 0, 0,
    //      0, 1, 0, 0},
    // };

    int outcomes[][4][4] = {
        {{1, 3, 4, 2},
         {4, 2, 1, 3},
         {3, 4, 2, 1},
         {2, 1, 3, 4}},
        {{2, 1, 4, 3},
         {3, 4, 1, 2},
         {4, 2, 3, 1},
         {1, 3, 2, 4}},
    };

    // cout << (equal(SolvePuzzle(clues[0]), outcomes[0])) << endl;
    // cout << (equal(SolvePuzzle(clues[1]), outcomes[1]));
    vector<vector<int>> test = {{2, 1, 4, 3},
                                {3, 4, 1, 2},
                                {4, 2, 3, 1},
                                {1, 3, 2, 4}};
    cout << valid(test);
}
