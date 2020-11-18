//다이나믹 프로그래밍(Dynamic Programming): 동적 계획법 - "중복되는 연산을 줄이자"
// 1. 큰 문제를 작은 문제로 나눌 수 있다.
// 2. 작은 문제에서 구한 정답은 그것을 포함하는 큰 문제에서도 동일하다.

//파일을 합쳐 하나로 모으는 최소 비용을 구하는 문제
//https://breakcoding.tistory.com/297
//https://camelsource.tistory.com/35
//http://melonicedlatte.com/algorithm/2018/03/22/051337.html
#include <iostream>
#include <algorithm>
using namespace std;
int INF = 1000000007;

int arr[501], sum[501], dp[501][501];

int main() {

	int N, T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cin >> N;
		for (int i = 1; i <= N; ++i) {
			cin >> arr[i];
			sum[i] = sum[i - 1] + arr[i];
		}
		for (int gap = 1; gap < N; ++gap) { //gap을 1씩 늘려가면서 돌아가는데 dp[i][j]에서 i와 j의 차이(간격)를 정해주는 for문이다.
			for (int i = 1; i + gap <= N; ++i) {// i를 1씩 늘려가면서 돌아가는데 dp[i][j]에서 i를 정해주는 for문이다.
				int j = i + gap;
				dp[i][j] = INF;
				for (int k = i; k < j; ++k) {//k를 1씩 늘려가면서 돌아간다. 파일을 합칠 때에는 두 개의 파일을 합쳐야 한다.
					dp[i][j] = min(dp[i][j], 
								dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
				}
			}
		}
		cout << dp[1][N] << '\n';
	}


	return 0;
}