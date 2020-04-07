// https://leetcode.com/problems/ugly-number-ii/
class Solution
{
public:
  int nthUglyNumber(int n)
  {

    if (n == 1)
    {
      return 1;
    }

    // take ugly vector starting from 1
    vector<int> ugly;
    ugly.push_back(1);

    // Keep pointers for 2,3,5 to multiply
    int i2 = 0, i3 = 0, i5 = 0;
    int nextMultipleOf2 = 2; // (2*ugly[i2])
    int nextMultipleOf3 = 3; // (3*ugly[i3])
    int nextMultipleOf5 = 5; // (5*ugly[i5])

    for (int i = 1; i < n; i++)
    {

      // Choose min of 3 options
      int nextUglyNo = min(nextMultipleOf2, min(nextMultipleOf3, nextMultipleOf5));

      // Add in array
      ugly.push_back(nextUglyNo);

      // If multiple of 2 move i2 by one
      if (nextUglyNo == nextMultipleOf2)
      {
        i2++;
        nextMultipleOf2 = ugly[i2] * 2;
      }

      // Don't use else if to handle cases like 6 (2*3) and (3*2)
      // So in case of 6 both pointers will move forward
      if (nextUglyNo == nextMultipleOf3)
      {
        i3++;
        nextMultipleOf3 = ugly[i3] * 3;
      }
      if (nextUglyNo == nextMultipleOf5)
      {
        i5++;
        nextMultipleOf5 = ugly[i5] * 5;
      }
    }
    return ugly.back();
  }
};