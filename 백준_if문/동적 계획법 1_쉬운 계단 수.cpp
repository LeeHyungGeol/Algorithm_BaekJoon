#include <iostream>
using namespace std;
#define tenBillion 1000000000
int main() {
	
	int N, sum = 0;
	cin >> N;
	int dp[101][10]; // [자릿수][ 0 ~ 9 까지의 수]

	dp[1][0] = 0; //1번째 자릿수가 0일 때의 값은 0이다. 
	for (int i = 1; i <= 9; ++i) { //N이 1일 때, 0을 제외하고 1,2,3,..8,9의 각각의 값이 1이다. 
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; ++i) { // i 번째 자리수(dp[i][0], dp[i][1] ... dp[i][9])의 0, 1, 9 에서의 예외처리를 잘해주자.
		dp[i][0] = dp[i - 1][1] % tenBillion; // i번째 자리수가 0인 경우 //i-1번째 자리수 1애서만 온다.
		
		if (dp[i - 1][0] == 0) // i번째 자리수가 1인 경우 //i-1번째 자리수 0애서만 온다.
			dp[i][1] = 1; //dp[i-1][0]의 값이 0이면 1을 넣어준다.
		else
			dp[i][1] = dp[i - 1][0]; //dp[i-1][0]의 값이 0이 아니면 dp[i-1][0]의 값을 넣어준다.
		dp[i][1] += dp[i - 1][2]; //dp[i][1]의 값은 dp[i-1][0], dp[i-1][2]에서 온다. 
		dp[i][1] %= tenBillion;

		for (int j = 2; j <= 8; ++j) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
			dp[i][j] %= tenBillion;
		}

		dp[i][9] = dp[i - 1][8] % tenBillion;
	}

	for (int i = 1; i <= 9; ++i) { //N번째 자리의 수가 0일 수가 없기 때문에  
		sum += dp[N][i];           //ex) 03234 - 이런 수는 존재하지 않는다.
		sum %= tenBillion;
	}
	cout << sum << '\n';

}
