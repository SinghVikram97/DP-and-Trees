// https://www.geeksforgeeks.org/activity-selection-problem-greedy-algo-1/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool myComp(pair<ll, ll> &a, pair<ll, ll> &b)
{
  if (a.second == b.second)
  {
    return a.first < b.first;
  }
  else
  {
    return a.second < b.second;
  }
}
ll solve(vector<pair<ll, ll>> &activities, int n)
{
  // Pick activity
  int currentFinishTime = activities[0].second;

  // Find next activity with start time just greater than current finish time
  int totalActivities = 1;

  for (int i = 1; i < n; i++)
  {

    if (activities[i].first >= currentFinishTime)
    {
      totalActivities++;
      currentFinishTime = activities[i].second;
    }
    else
    {
      continue;
    }
  }
  return totalActivities;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<pair<ll, ll>> activities(n);

    // start times
    for (int i = 0; i < n; i++)
    {
      cin >> activities[i].first;
    }

    // end times
    for (int j = 0; j < n; j++)
    {
      cin >> activities[j].second;
    }

    // sort according to finish time
    sort(activities.begin(), activities.end(), myComp);

    // for (int i = 0; i < n; i++)
    // {
    //   cout << activities[i].first << " " << activities[i].second << endl;
    // }

    cout << solve(activities, n) << endl;
  }
}