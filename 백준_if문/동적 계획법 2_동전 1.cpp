//�� �̻� ������ �ʴ� ���� �������ν� ���� ���⵵�� ����Ű�� ����. �޸� ���ѿ� �ָ�.
//https://yabmoons.tistory.com/491 
#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;//������ ��ġ
int dp[100001] = { 0 };
int main() {
	
	int n, k, x;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		arr.push_back(x);
	}
	dp[0] = 1;//�������� ����ؼ� 0���� ���� �� �ִ� ���� �� ���� -> �ƹ��� ������ ������� �ʴ� 1���� ����� �ִ�.
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j <= k; ++j) {
			if (j >= arr[i])
				dp[j] += dp[j - arr[i]];
		}
	}
	cout << dp[k] << '\n';
	return 0;
}