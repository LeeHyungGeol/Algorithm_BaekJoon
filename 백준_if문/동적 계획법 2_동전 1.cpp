//���̳��� ���α׷���(Dynamic Programming): ���� ��ȹ�� - "�ߺ��Ǵ� ������ ������"
// 1. ū ������ ���� ������ ���� �� �ִ�.
// 2. ���� �������� ���� ������ �װ��� �����ϴ� ū ���������� �����ϴ�.
//�� �̻� ������ �ʴ� ���� �������ν� ���� ���⵵�� ����Ű�� ����. �޸� ���ѿ� �ָ�.
//https://yabmoons.tistory.com/491 
#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;//������ ��ġ
//int dp[100001] = { 0 };
int main() {
	
	int n, k, x;
	cin >> n >> k;//������ ����, k��ŭ�� ��ġ
	for (int i = 0; i < n; ++i) {
		cin >> x;
		arr.push_back(x);
	}
	vector<int> dp(k + 1, 0);
	dp[0] = 1;// �ڱ��ڽ� ��ŭ�� ��ġ�� ������ ��� �ε����� 0�� �Ǿ 1�� �̸� �ʱ�ȭ.
	for (int i = 0; i < n; ++i) {
		for (int j = arr[i]; j <= k; ++j) {
			if (j >= arr[i])
				dp[j] += dp[j - arr[i]];
		}

	}
	cout << dp[k] << '\n';
	return 0;
}