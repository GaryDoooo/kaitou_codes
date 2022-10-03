#include <iostream>
using namespace std;
int main()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int k = 0; k <= 0; k++)
            {
                // if (i != k != j)
                // {
                if (i + j + k == i * j * k)
                    cout << i << j << k << endl;
                // }
            }
        }
    }
}