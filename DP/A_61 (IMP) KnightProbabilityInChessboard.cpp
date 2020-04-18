// https://leetcode.com/problems/knight-probability-in-chessboard/
// Basic recursion
class Solution
{
public:
  vector<vector<int>> direction = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};
  double helper(int N, int K, int r, int c)
  {

    // Out of board
    if (r >= N || c >= N)
    {
      return 0.0;
    }

    // Out of board
    if (r < 0 || c < 0)
    {
      return 0.0;
    }

    // Went k steps and still in board
    if (K == 0)
    {
      return 1.0;
    }

    // Can move in 8 directions
    double total = 0; // total no of moves that results in staying on board from r,c

    for (int i = 0; i < direction.size(); i++)
    {
      total += helper(N, K - 1, r + direction[i][0], c + direction[i][1]);
    }

    // Out of 8 possible moves
    // Can move in totalNum of moves to stay on board
    // So probability is total/8
    return total / 8.0;
  }

  double knightProbability(int N, int K, int r, int c)
  {
    return helper(N, K, r, c);
  }
};

// Memo
class Solution
{
public:
  vector<vector<int>> direction = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};
  double helper(int N, int K, int r, int c, vector<vector<vector<double>>> &dp)
  {

    // Out of board
    if (r >= N || c >= N)
    {
      return 0.0;
    }

    // Out of board
    if (r < 0 || c < 0)
    {
      return 0.0;
    }

    // Went k steps and still in board
    if (K == 0)
    {
      return 1.0;
    }

    if (dp[r][c][K] != -1)
    {
      return dp[r][c][K];
    }

    // Can move in 8 directions
    double total = 0; // total no of moves that results in staying on board from r,c

    for (int i = 0; i < direction.size(); i++)
    {
      total += helper(N, K - 1, r + direction[i][0], c + direction[i][1], dp);
    }

    // Out of 8 possible moves
    // Can move in totalNum of moves to stay on board
    // So probability is total/8
    dp[r][c][K] = total / 8.0;

    return dp[r][c][K];
  }

  double knightProbability(int N, int K, int r, int c)
  {
    vector<vector<vector<double>>> dp(N + 1, vector<vector<double>>(N + 1, vector<double>(K + 1, -1)));
    return helper(N, K, r, c, dp);
  }
};