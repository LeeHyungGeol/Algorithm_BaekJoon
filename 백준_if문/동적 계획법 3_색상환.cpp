//https://akim9905.tistory.com/71  - BottomUp
//https://jaimemin.tistory.com/556  - BottomUp
//https://kibbomi.tistory.com/124  - TopDown
//dp[N][K] = N 개 짜리 색상환 중에서 K 개를 인접하지 않게 칠하는 경우의 수
// 1. 서로 인접하지 않는 것에 대한 점화식
// 1. i번째 색을 선택하는 경우 : (i번째 색을 선택했기 때문에, i-1번 색 제외) => i-2개의 색상환 중에서 k-1개의 색을 색칠하는 경우 = dp[i-2][k-1]
// 1. i번째 색을 선택하지 않는 경우 : i-1 개의 색상환 중에서 k개의 색을 색칠하는 경우 = dp[i-1][k]
// 2. 첫번째 색과 N번째 색을 동시에 칠하지 않는 것에 대한 점화식
// 2. N번째 색을 색칠하는 경우 : "일렬로 있을 때" 첫번째 색과 N-1번째 색을 색칠하면 안된다 : N-3개의 색상환 중에서 K-1개의 색을 색칠하는 경우와 동일하다 = dp[N-3][K-1]
// 2. N번째 색을 색칠하지 않는 경우 : "일렬로 있을 때" N번째 색만 색칠하지 않으면 된다(첫번째 색, N-1번째 색은 상관하지 않아도 된다) : N-1개의 색상환 중에서 K개의 색을 색칠하는 경우와 동일하다 = dp[N-1[K]
// BOJ 2156번. 포도주 시식 문제와 비슷 : 규칙을 찾아서 점화식을 잘 세우자!!
#include <iostream>
#include <string.h>//memset
#define mod 1000000003
using namespace std;
int N;//색상환에 포함된 색의 개수, N(4≤N≤1,000)
int K;//N색상환에서 선택할 색의 개수 K(1≤K≤N)
int dp[1001][1001] = { 0 };
int func(int colors, int choose);
int main() {

	cin >> N;
	cin >> K;
	memset(dp, -1, sizeof(dp));
	/*for (int i = 1; i <= N; ++i) {
		dp[i][1] = i;
		dp[i][0] = 1;
	}
	for (int i = 2; i <= N; ++i) {
		for (int j = 2; j <= K; ++j) {
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % mod;
		}
	}
	cout << (dp[N - 3][K - 1] + dp[N - 1][K]) % mod << '\n';*/

	/*for (int i = 1; i <= 3; ++i) {
		dp[i][1] = i;
	}
	for (int i = 4; i <= N; ++i) {
		int maxChoose = i / 2;
		for (int j = 1; j <= maxChoose; ++j) {
			if (j == 1)
				dp[i][j] = i;
			else
				dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % mod;
		}
	}*/
	//cout << dp[N][K] << '\n';
	cout << func(N, K) << '\n';
	return 0;
}
int func(int colors, int choose) {
	if (colors == 0 || colors < choose * 2) return 0;
	if (choose == 1) return colors;

	if (dp[colors][choose] != -1)
		return dp[colors][choose];
	
	return dp[colors][choose] = (func(colors - 2, choose - 1) + func(colors - 1, choose)) % mod;
}