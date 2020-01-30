/// Order matters
#include <bits/stdc++.h>
using namespace std;
int number_of_ways(int total_value, vector<int> coins, int current_value)
{
  if (current_value == total_value)
  {
    return 1; /// Sucessful
  }
  else if (current_value > total_value)
  {
    return 0; /// Unsucessful
  }
  int ways = 0;
  for (int i = 0; i < coins.size(); i++)
  {
    ways = ways + number_of_ways(total_value, coins, current_value + coins[i]);
  }
  return ways;
}
int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> v(m);
  for (int i = 0; i < m; i++)
  {
    cin >> v[i];
  }
  cout << number_of_ways(n, v, 0);
}