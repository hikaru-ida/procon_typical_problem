#include <iostream>
#include <vector>
#include "./../../lib/debug/my_debug.h"
using namespace std;

/*
 * 問題名：ゲーム
 * url: http://tdpc.contest.atcoder.jp/tasks/tdpc_game
 *
 * dp[i][j]: 左の山にi個、右の山にj個のものが残っている状態で、
 * その状態から終了までに先手が得られる価値の合計。
 *
 * 先攻、後攻の判定は(A+B-i-j)ですればよい。
 * i,jは山に残っている個数なので、これを合計から
 * 引くと取った個数となる。
 * 偶数なら先攻の番、奇数なら後攻の番となる。
 */
int main() {
  int A, B;
  cin >> A >> B;
  vector<int> a(A+1), b(B+1);
  for(int i=0;i<A;i++) cin >> a[i+1];
  for(int i=0;i<B;i++) cin >> b[i+1];

  vector< vector<int> > dp(A+1, vector<int>(B+1, 0));
  for(int i=0;i<=A;i++) {
    for(int j=0;j<=B;j++) {
      if(i==0 && j==0) continue;
      // 先行
      if((A+B-i-j) % 2 == 0) {
        if(i==0) {
          dp[0][j] = dp[0][j-1] + b[B-j+1];
        } else if(j ==0) {
          dp[i][0] = dp[i-1][0] + a[A-i+1];
        } else {
          dp[i][j] = max(dp[i-1][j]+a[A-i+1], dp[i][j-1]+b[B-j+1]);
        }
      } else {  //後攻
        if(i==0)
          dp[0][j] = dp[0][j-1];
        else if(j==0)
          dp[i][0] = dp[i-1][0];
        else
          dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
  cout << dp[A][B] << endl;
  show_matrix(dp);


}

