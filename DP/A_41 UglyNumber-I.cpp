// https://leetcode.com/problems/ugly-number/
class Solution
{
public:
  void divide(int &num, int div)
  {
    while (num % div == 0)
    {
      num = num / div;
    }
  }

  bool isUgly(int num)
  {
    if (num == 1)
    {
      return true;
    }
    if (num == 0)
    {
      return false;
    }
    divide(num, 2);
    divide(num, 3);
    divide(num, 5);

    if (num == 1)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};