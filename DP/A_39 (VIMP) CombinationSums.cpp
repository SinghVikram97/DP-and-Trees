//https://leetcode.com/problems/combination-sum/
class Solution
{
public:
  void solve(vector<int> &v, int target, int index, vector<int> temp, vector<vector<int>> &ans)
  {

    int n = v.size();

    if (target == 0)
    {
      ans.push_back(temp);
      return;
    }

    if (index == n || target < 0)
    {
      return;
    }

    // Le skte hain ya nhi le skte

    // Don't take
    solve(v, target, index + 1, temp, ans);

    // take
    temp.push_back(v[index]);

    solve(v, target - v[index], index, temp, ans);

    temp.pop_back();
  }

  vector<vector<int>> combinationSum(vector<int> &candidates, int target)
  {

    vector<vector<int>> ans;
    vector<int> temp;
    solve(candidates, target, 0, temp, ans);
    return ans;
  }
};

// (IMP)
// https://leetcode.com/problems/combination-sum-ii/
class Solution
{
public:
  void backtrack(vector<int> &candidates, int target, int start, vector<int> temp, vector<vector<int>> &ans)
  {

    int n = candidates.size();

    if (target == 0)
    {
      ans.push_back(temp);
      return;
    }

    if (start >= n || target < 0)
    {
      return;
    }

    // At any point we can take all the numbers from start to n

    for (int i = start; i < n; i++)
    {

      // Skip duplicates
      // At each position a number can only appear once
      // If we need 2 again to make 5 it can come at next position 1,2,_ not again at 1,_
      if (i > start && candidates[i] == candidates[i - 1])
      {
        continue;
      }

      temp.push_back(candidates[i]);
      // No can be used only once so start is i+1
      backtrack(candidates, target - candidates[i], i + 1, temp, ans);
      temp.pop_back();
    }
  }

  vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
  {

    vector<vector<int>> ans;
    vector<int> temp;
    sort(candidates.begin(), candidates.end());
    backtrack(candidates, target, 0, temp, ans);
    return ans;
  }
};

// https://leetcode.com/problems/combination-sum-iv/submissions/
// (IMP)
class Solution
{
public:
  void backtrack(vector<int> &nums, int target, vector<int> temp, vector<vector<int>> &ans)
  {

    if (target == 0)
    {
      ans.push_back(temp);
      return;
    }

    if (target < 0)
    {
      return;
    }

    // everytime we start from 0 so need of seperate start index
    // as we need 1,3 as well as 3,1
    // if we use start in 1,2,3,,, we pick 3 then we come to end of array
    // so at each position any number in array can come
    for (int i = 0; i < nums.size(); i++)
    {
      temp.push_back(nums[i]);
      backtrack(nums, target - nums[i], temp, ans);
      temp.pop_back();
    }
  }

  vector<vector<int>> combinationSum4(vector<int> &nums, int target)
  {
    vector<vector<int>> ans;
    vector<int> temp;
    backtrack(nums, target, temp, ans);
    return ans;
  }
};

// (VIMP) if we need to print just no of combinations use dp
// https://leetcode.com/problems/combination-sum-iv/
class Solution
{
public:
  int backtrack(vector<int> &nums, int target, vector<int> &dp)
  {

    if (target == 0)
    {
      return 1;
    }

    if (target < 0)
    {
      return 0;
    }

    if (dp[target] == -1)
    {
      // everytime we start from 0 so need of seperate start index
      // as we need 1,3 as well as 3,1
      // if we use start in 1,2,3,,, we pick 3 then we come to end of array
      // so at each position any number in array can come
      int ans = 0;
      for (int i = 0; i < nums.size(); i++)
      {

        ans += backtrack(nums, target - nums[i], dp);
      }
      dp[target] = ans;
    }
    return dp[target];
  }

  int combinationSum4(vector<int> &nums, int target)
  {

    vector<int> dp(target + 5);
    for (int i = 0; i < dp.size(); i++)
    {
      dp[i] = -1;
    }
    return backtrack(nums, target, dp);
  }
};