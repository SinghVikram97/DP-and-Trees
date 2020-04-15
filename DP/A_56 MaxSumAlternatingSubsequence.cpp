// https://www.geeksforgeeks.org/maximum-sum-alternating-subsequence-sum/
//  Same as previous just store sum instead of length
// -1,0,1 doesn't work in this case
// ex. 8 2 7 10
// we need to keep both up and down
#include <bits/stdc++.h>
using namespace std;
int help(vector<int> &v, int n)
{

  if (n == 0)
  {
    return 0;
  }

  else if (n == 1)
  {
    return v[0];
  }

  vector<int> up(n);   // Max sum alternating subsequence ending at i with last element > prev element in series
  vector<int> down(n); // Max sum alternating subsequence ending at i with last element < prev element in series

  up[0] = v[0];
  down[0] = v[0];

  for (int i = 1; i < n; i++)
  {

    up[i] = v[i];
    down[i] = v[i];

    for (int j = i - 1; j >= 0; j--)
    {

      if (v[i] > v[j])
      {
        up[i] = max(up[i], down[j] + v[i]);
      }
      else if (v[i] < v[j])
      {
        down[i] = max(down[i], up[j] + v[i]);
      }
      else
      {
        // Equal no possibility
      }
    }
  }

  int ans = -1;

  for (int i = 0; i < n; i++)
  {
    ans = max(ans, max(up[i], down[i]));
  }

  return ans;
}
int main()
{
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  cout << help(v, n) << endl;
}
