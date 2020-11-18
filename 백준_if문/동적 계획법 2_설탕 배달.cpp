//���̳��� ���α׷���(Dynamic Programming): ���� ��ȹ�� - "�ߺ��Ǵ� ������ ������"
// 1. ū ������ ���� ������ ���� �� �ִ�.
// 2. ���� �������� ���� ������ �װ��� �����ϴ� ū ���������� �����ϴ�.
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 10000
using namespace std;
int main() {
	int arr[3] = { 0,3,5 }; //5 Kg ����, 3 Kg ����
	int N;//���� ���� (3 �� N �� 5000)
	cin >> N;
	vector<int> dp(N + 1, INF);
	dp[0] = 0;
	for (int i = 1; i <= 2; ++i) {
		for (int j = arr[i]; j <= N; ++j) {
			if (dp[j - arr[i]] != INF)//(i-k) ���� ����� ����� �����ϴ� ���
				dp[j] = min(dp[j], dp[j - arr[i]] + 1);
		}
	}
	if (dp[N] == INF)
		cout << "-1" << '\n';
	else
		cout << dp[N] << '\n';

	return 0;
}