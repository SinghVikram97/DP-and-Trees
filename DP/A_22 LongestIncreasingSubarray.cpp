// https://practice.geeksforgeeks.org/problems/longest-increasing-subarray/0

// 5 6 3 5 7

// 6 > 5
// 3 < 5

// Since 6 > 5 so any number less than 5 less than 6 also
// So increasing subarary starting with 6 would be of length 1 only
// Since next element less than 6
// So we start our search from 3

#include <bits/stdc++.h>
using namespace std;
int help(vector<int> &v, int n)
{

  if (n == 0)
  {
    return 0;
  }

  int final_ans = 1;
  int temp_ans = 1;
  for (int i = 1; i < n; i++)
  {

    if (v[i] > v[i - 1])
    {
      temp_ans++;
      final_ans = max(final_ans, temp_ans);
    }
    else
    {
      temp_ans = 1;
      final_ans = max(final_ans, temp_ans);
    }
  }
  return final_ans;
}
int main()
{

  int t;
  cin >> t;
  while (t--)
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
}