//���̳��� ���α׷���(Dynamic Programming): ���� ��ȹ�� - "�ߺ��Ǵ� ������ ������"
// 1. ū ������ ���� ������ ���� �� �ִ�.
// 2. ���� �������� ���� ������ �װ��� �����ϴ� ū ���������� �����ϴ�.

//������ ���� �ϳ��� ������ �ּ� ����� ���ϴ� ����
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
		for (int gap = 1; gap < N; ++gap) { //gap�� 1�� �÷����鼭 ���ư��µ� dp[i][j]���� i�� j�� ����(����)�� �����ִ� for���̴�.
			for (int i = 1; i + gap <= N; ++i) {// i�� 1�� �÷����鼭 ���ư��µ� dp[i][j]���� i�� �����ִ� for���̴�.
				int j = i + gap;
				dp[i][j] = INF;
				for (int k = i; k < j; ++k) {//k�� 1�� �÷����鼭 ���ư���. ������ ��ĥ ������ �� ���� ������ ���ľ� �Ѵ�.
					dp[i][j] = min(dp[i][j], 
								dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
				}
			}
		}
		cout << dp[1][N] << '\n';
	}


	return 0;
}