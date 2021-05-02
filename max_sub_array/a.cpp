#include <vector>
#include <iostream>

using namespace std;

int maxSequence(const vector<int> &arr)
{
  //...''
  int res = 0;
  for (auto i = 0; i < arr.size(); i++)
  {
    int s = 0;
    for (auto j = i; j < arr.size(); j++)
    {
      s += arr[j];
      if (s > res)
        res = s;
    }
  }
  return res;
}

int main()
{
  vector<int> a = {-1, -1, 3};
  cout << maxSequence(a) << endl;
}
