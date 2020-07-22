// https://leetcode.com/problems/rotting-oranges/

class Solution
{
public:
  int orangesRotting(vector<vector<int>> &grid)
  {

    int m = grid.size();
    int n = grid[0].size();

    queue<pair<int, int>> mq;

    // Put all rotten oranges in a queue
    int count_fresh = 0;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {

        if (grid[i][j] == 2)
        {
          mq.push(make_pair(i, j));
        }
        else if (grid[i][j] == 1)
        {
          count_fresh++;
        }
      }
    }

    if (count_fresh == 0)
    {
      return 0;
    }

    int count = 0;

    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!mq.empty())
    {

      count++;

      int size = mq.size();

      // Rot all oranges in this second (count)

      for (int i = 0; i < size; i++)
      {

        pair<int, int> point = mq.front();
        mq.pop();

        for (int j = 0; j < dirs.size(); j++)
        {

          int x = point.first + dirs[j][0];
          int y = point.second + dirs[j][1];

          if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == 0 || grid[x][y] == 2)
          {
            continue;
          }

          // Mark it as rotten
          grid[x][y] = 2;

          // Push to queue
          mq.push(make_pair(x, y));

          // Decrease count_fresh
          count_fresh--;
        }
      }
    }

    if (count_fresh != 0)
    {
      return -1;
    }
    else
    {
      // One extra bfs for when all are rotten
      return count - 1;
    }
  }
};