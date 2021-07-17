#include <iostream>
#include <string>
using namespace std;

int binToDeci(string n)
{
    // cout << n << endl;
    int res = 0;
    int counter = 1;
    int d = 0;
    int e = n.length();
    for (int p = 1; p <= e; p++)
    {
        // cout << n.back() << endl;
        if (n.back() == '1')
        {
            d = 1;
        }
        else
        {
            d = 0;
        }
        n.pop_back();
        // cout << n << endl;
        res += d * (counter);
        // cout << res;
        counter *= 2;
    }
    return res;
}

int main()
{
    string inp = "";
    cin >> inp;
    int dec1, dec2, dec3, dec4;
    dec1 = binToDeci(inp.substr(0, 8));
    dec2 = binToDeci(inp.substr(8, 8));
    dec3 = binToDeci(inp.substr(16, 8));
    dec4 = binToDeci(inp.substr(24, 8));

    cout << dec1 << "." << dec2 << "." << dec3 << "." << dec4;
}