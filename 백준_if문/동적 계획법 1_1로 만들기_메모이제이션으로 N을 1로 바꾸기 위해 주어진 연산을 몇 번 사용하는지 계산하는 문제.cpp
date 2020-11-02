//�޸������̼����� N�� 1�� �ٲٱ� ���� �־��� ������ �� �� ����ϴ��� ����ϴ� ����
#include <iostream>
#include <algorithm>
using namespace std;

//bottom-up���
long long int dp[1000001] = { 0 }; //d, dp, memo, cache, table ���..

int main() {
	int N;
	cin >> N;
	for (int i = 2; i <= N; ++i) {
		//dp[i] = min(dp[i], dp[i - 1] + 1); //dp�� ������ �ʱ�ȭ �� ��, INF�� �����ϸ� ��� ����
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0) {
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
		if (i % 2 == 0) {
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
	}
	cout << dp[N] << '\n';
	return 0;
}