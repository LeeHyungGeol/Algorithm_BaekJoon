//https://akim9905.tistory.com/71  - BottomUp
//https://jaimemin.tistory.com/556  - BottomUp
//https://kibbomi.tistory.com/124  - TopDown
//dp[N][K] = N �� ¥�� ����ȯ �߿��� K ���� �������� �ʰ� ĥ�ϴ� ����� ��
// 1. ���� �������� �ʴ� �Ϳ� ���� ��ȭ��
// 1. i��° ���� �����ϴ� ��� : (i��° ���� �����߱� ������, i-1�� �� ����) => i-2���� ����ȯ �߿��� k-1���� ���� ��ĥ�ϴ� ��� = dp[i-2][k-1]
// 1. i��° ���� �������� �ʴ� ��� : i-1 ���� ����ȯ �߿��� k���� ���� ��ĥ�ϴ� ��� = dp[i-1][k]
// 2. ù��° ���� N��° ���� ���ÿ� ĥ���� �ʴ� �Ϳ� ���� ��ȭ��
// 2. N��° ���� ��ĥ�ϴ� ��� : "�Ϸķ� ���� ��" ù��° ���� N-1��° ���� ��ĥ�ϸ� �ȵȴ� : N-3���� ����ȯ �߿��� K-1���� ���� ��ĥ�ϴ� ���� �����ϴ� = dp[N-3][K-1]
// 2. N��° ���� ��ĥ���� �ʴ� ��� : "�Ϸķ� ���� ��" N��° ���� ��ĥ���� ������ �ȴ�(ù��° ��, N-1��° ���� ������� �ʾƵ� �ȴ�) : N-1���� ����ȯ �߿��� K���� ���� ��ĥ�ϴ� ���� �����ϴ� = dp[N-1[K]
// BOJ 2156��. ������ �ý� ������ ��� : ��Ģ�� ã�Ƽ� ��ȭ���� �� ������!!
#include <iostream>
#include <string.h>//memset
#define mod 1000000003
using namespace std;
int N;//����ȯ�� ���Ե� ���� ����, N(4��N��1,000)
int K;//N����ȯ���� ������ ���� ���� K(1��K��N)
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