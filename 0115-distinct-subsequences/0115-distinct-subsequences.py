class Solution:
   def numDistinct(self, s: str, t: str) -> int:
       m, n = len(s), len(t)
       dp = [[0] * (n + 1) for _ in range(m + 1)]
       # Base case: empty target
       for i in range(m + 1):
           dp[i][0] = 1
       for i, sc in enumerate(s, 1):
           for j, tc in enumerate(t, 1):
               dp[i][j] = dp[i-1][j]
               if sc == tc:
                   dp[i][j] += dp[i-1][j-1]
       return dp[m][n]