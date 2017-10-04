#include <iostream>
#include <vector>

using namespace std;
/*
 * 問題名：コンテスト
 * url: http://tdpc.contest.atcoder.jp/tasks/tdpc_contest
 *
 * dp[i][j]: i問目までの問題を使って、j点の合計点ができるかどうかの真理値
 * indexに気をつける
 */
int main() {
  int n;
  std::cin >> n;
  std::vector<int> v(n);
  for(int i=0;i<n;i++) std::cin >> v[i];
  vector<vector<int> > dp(n+1, vector<int>(10010));
  dp[0][0] = 1;
  for(int i=1;i<=n;i++) {
    for(int j=0;j<=10010;j++) {
      dp[i][j] |= dp[i-1][j];
      if(j-v[i-1] >= 0)
        dp[i][j] |= dp[i-1][j-v[i-1]];
    }
  }
  int ans = 0;
  for(int j=0;j<10010;j++) {
    ans += dp[n][j];
  }
  cout << ans << endl;
}

