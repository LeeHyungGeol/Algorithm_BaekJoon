//LIS(Longest Increasing Subsequence) ���� �� �����ϴ� �κ� ���� ���� ����
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//bottom-up���
int main() {

	vector<int> v;
	int N, x, result = 0, dp[1001] = { 0 }, rdp[1001] = { 0 },max1=0,max2=0;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> x;
		v.push_back(x);
	}
	for (int i = 0; i < N; ++i) {
		dp[i] = rdp[i] = 1;
	}
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < i; ++j) {
			if (v[j] < v[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
				if (max1 < dp[i])
					max1 = dp[i];
			}
		}
	}
	//reverse(v.begin(), v.end()); //reverse�� ���� ���� �� �ȵ���?
	//reverse�� �ϸ� �ȵǴ� ����: reverse�� �ϸ� index������ �� �ٲ�� ������ ������ �ߺ��Ǵ� index�� �޶����� ������
	/*reverse(v.begin(), v.end());
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (v[j] < v[i]) {
				rdp[i] = max(rdp[i], rdp[j] + 1);
				if (max2 < rdp[i])
					max2 = rdp[i];
			}
		}
	}*/
	//cout << " max1 : " << max1 << " max2 : " << max2 << '\n';
	for (int i = N - 1; i >= 1; --i) {
		for (int j = N - 1; j > i; --j) {
			if (v[j] < v[i])
				rdp[i] = max(rdp[i], rdp[j] + 1);
		}
	}
	for (int i = 0; i < N; ++i) {
		if (result < dp[i] + rdp[i] - 1)
			result = dp[i] + rdp[i] - 1;
	}
	cout << result << '\n';
	return 0;
}