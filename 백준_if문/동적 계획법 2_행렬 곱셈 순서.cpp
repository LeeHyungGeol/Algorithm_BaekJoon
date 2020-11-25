//다이나믹 프로그래밍(Dynamic Programming): 동적 계획법 - "중복되는 연산을 줄이자"
// 1. 큰 문제를 작은 문제로 나눌 수 있다.
// 2. 작은 문제에서 구한 정답은 그것을 포함하는 큰 문제에서도 동일하다.

//모든 행렬을 곱하는데 필요한 곱셈 연산 횟수의 최솟값을 구하는 프로그램
//https://kevink1113.tistory.com/entry/C-%EB%B0%B1%EC%A4%80-11049-%ED%96%89%EB%A0%AC-%EA%B3%B1%EC%85%88-%EC%88%9C%EC%84%9C
//https://blog.naver.com/PostView.nhn?blogId=phj8498&logNo=221340992241
//https://mygumi.tistory.com/258
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 1e9; //10억
int arr[501][2] = {0};
int dp[501][501] = { 0 };
int main() {

	 //행렬의 크기 r과 c (1 ≤ r, c ≤ 500)
	int N, r, c;//행렬의 개수 N(1 ≤ N ≤ 500)
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i][0] >> arr[i][1];
	}
	/*for (int i = 1; i < N; ++i) {
		dp[i][i + 1] = arr[i][0] * arr[i][1] * arr[i + 1][1];
	}*/
	/*for (int m = 2; m <= N; ++m) {
		for (int i = 1; i + m <= N; ++i) {
			int j = i + m;
			for (int k = i; k < j; ++k) {
				int res = dp[i][k] + dp[k + 1][j] + (arr[i][0] * arr[k][1] * arr[j][1]);
				if (dp[i][j] == 0 || res < dp[i][j])
					dp[i][j] = res;
			}
		}
	}*/
	for (int m = 1; m <= N; ++m) {
		for (int i = 1; i + m <= N; ++i) {
			int j = i + m;
			dp[i][j] = INF;
			for (int k = i; k < j; ++k) {
				dp[i][j] = min(dp[i][j], 
							dp[i][k] + dp[k + 1][j] + (arr[i][0] * arr[k][1] * arr[j][1]));
			}
		}
	}
	cout << dp[1][N] << '\n';
	return 0;
}