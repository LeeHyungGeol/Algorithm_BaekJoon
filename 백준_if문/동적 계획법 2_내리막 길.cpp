//내리막길로만 이동하는 경우의 수를 구하는 문제
//https://sihyungyou.github.io/baekjoon-1520/
//https://wootool.tistory.com/83
#include <iostream>
using namespace std;

int vecX[5] = { 0,1,0,-1,0 };//우,하,좌,상로 움직이는 X좌표
int vecY[5] = { 0,0,1,0,-1 };//우,하,좌,상로 움직이는 Y좌표
int arr[501][501] = { 0 };
long long int dp[501][501] = { 0 };
int M, N;//M: 세로, N: 가로
int dfs(int y, int x);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;
	for (int i = 1; i <= M; ++i) {
		for (int j = 1; j <= N; ++j) {
			dp[i][j] = -1;
			cin >> arr[i][j];
		}
	}
	cout << dfs(1, 1) << '\n';
	return 0;
}
int dfs(int y, int x) {
	if (y == M && x == N)
		return 1;
	if (dp[y][x] == -1) {
		dp[y][x] = 0;
		for (int i = 1; i <= 4; ++i) {
			int newX = x + vecX[i];
			int newY = y + vecY[i];
			if (newX > 0 && newX <= N && newY > 0 && newY <= M && arr[y][x] > arr[newY][newX])
				dp[y][x] += dfs(newY, newX);
		}
	}
	return dp[y][x];
}