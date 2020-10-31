#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//�� ���� ��� ĭ���� 
//�ִ��� �����ϸ鼭 ���� ��ȹ������ Ǫ�� ����

int main() {

	int N, result = 0, dp[501][501] = { 0 };
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= i; ++j) {
			cin >> dp[i][j];
		}
	}
	/*for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= i; ++j) {
			cout << dp[i][j] << " ";
		}
		cout << '\n';
	}*/
	if (N == 1) {
		cout << dp[1][1] << '\n';
		return 0;
	}
	
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= i; ++j) {
			int left, right;
			if ((j - 1) == 0)
				left = 0;
			else
				left = dp[i - 1][j - 1];
			if ((i-1) < (j))
				right = 0;
			else
				right = dp[i - 1][j];
			dp[i][j] = dp[i][j] + max(left, right);
		}
	}

	for (int j = 1; j <= N; ++j) {
		//cout << " i : " << j << " dp[N][j] : " << dp[N][j] << '\n';
		if (result < dp[N][j])
			result = dp[N][j];
	}
	cout << result << '\n';
	return 0;
}
