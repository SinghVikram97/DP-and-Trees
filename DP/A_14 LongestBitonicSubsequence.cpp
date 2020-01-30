// https://www.interviewbit.com/problems/length-of-longest-subsequence/

int Solution::longestSubsequenceLength(const vector<int> &A)
{

  int n = A.size();

  if (n == 0)
  {
    return 0;
  }

  // Find longest increasing subsquence from front

  vector<int> lis1(n);

  for (int i = 0; i < n; i++)
  {

    lis1[i] = 1;

    for (int j = i - 1; j >= 0; j--)
    {

      if (A[j] < A[i])
      {
        lis1[i] = max(lis1[i], 1 + lis1[j]);
      }
    }
  }

  // Find longest increasing subsquence from back

  vector<int> lis2(n);

  for (int i = n - 1; i >= 0; i--)
  {

    lis2[i] = 1;

    for (int j = i + 1; j < n; j++)
    {

      if (A[j] < A[i])
      {
        lis2[i] = max(lis2[i], 1 + lis2[j]);
      }
    }
  }

  // max of Sum of both-1 is the answer

  int ans = -1;

  for (int i = 0; i < n; i++)
  {

    ans = max(ans, lis1[i] + lis2[i] - 1);
  }

  return ans;
}
