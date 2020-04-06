//https://leetcode.com/problems/merge-intervals/
bool myComp(vector<int> &a, vector<int> &b)
{

  // sort by start times
  if (a[0] == b[0])
  {
    return a[1] < b[1];
  }
  else
  {
    return a[0] < b[0];
  }
}
class Solution
{
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals)
  {

    if (intervals.size() <= 1)
    {
      return intervals;
    }

    sort(intervals.begin(), intervals.end(), myComp);

    vector<vector<int>> ans;

    ans.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++)
    {

      int finishTime = ans.back()[1];

      if (intervals[i][0] <= finishTime)
      {

        if (intervals[i][1] <= finishTime)
        {
          continue;
        }
        else
        {
          ans.back()[1] = intervals[i][1];
        }
      }
      else
      {
        ans.push_back(intervals[i]);
      }
    }

    return ans;
  }
};