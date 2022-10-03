#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int sqrtn = sqrt(n);
    int squares[sqrtn + 2];
    squares[0] = 0;
    int squares_in = 1;
    for (int i = 1; i <= sqrtn; i++)
    {
        squares[squares_in] = i * i;
        squares_in++;
    }

    // for (int i = 0; i < sqrtn + 1; i++)
    //     cout << squares[i] << " ";
    // cout << endl;
    for (int n1 = 0; n1 <= sqrtn; n1++)
    {

        for (int n2 = n1; n2 <= sqrtn; n2++)
        {

            for (int n3 = n2; n3 <= sqrtn; n3++)
            {
                for (int n4 = n3; n4 <= sqrtn; n4++)
                {
                    if (n == squares[n1] + squares[n2] + squares[n3] + squares[n4])
                    {
                        cout << sqrt(squares[n1]) << " " << sqrt(squares[n2]) << " " << sqrt(squares[n3]) << " " << sqrt(squares[n4]) << endl;
                        // return 0;
                    }
                }
            }
        }
    }
}