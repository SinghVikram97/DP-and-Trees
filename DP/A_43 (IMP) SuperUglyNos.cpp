// https://leetcode.com/problems/super-ugly-number/
class Solution
{
public:
  int nthSuperUglyNumber(int n, vector<int> &primes)
  {

    if (n == 1)
    {
      return 1;
    }

    vector<int> ugly;
    ugly.push_back(1);

    int primesSize = primes.size();

    // Every pointer points to zero initially
    vector<int> point(primesSize);

    for (int i = 1; i < n; i++)
    {

      int nextUglyNo = INT_MAX - 5;

      for (int j = 0; j < primes.size(); j++)
      {
        nextUglyNo = min(nextUglyNo, ugly[point[j]] * primes[j]);
      }

      ugly.push_back(nextUglyNo);

      for (int j = 0; j < primes.size(); j++)
      {

        // Increase pointers for all those which match
        // like we increase for 2 and 3 when we got 6 in ugly nos-2
        if (nextUglyNo == ugly[point[j]] * primes[j])
        {
          point[j]++;
        }
      }
    }
    return ugly.back();
  }
};