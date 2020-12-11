//O(N^2) LIS�� ����ϴ� ����
//dp[i] : arr[i]�� ������ ���ҷ� ������ �κ� ������ �ִ� ����
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int N;// ���� A�� ũ�� N (1 �� N �� 1,000)
int arr[1001] = { 0 };//(1 �� Ai �� 1,000)
int dp[1001] = { 0 };
int main() {
	cin >> N;
	int x, longestLength = 1;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		dp[i] = 1;//�κ� ������ ���� ��, ���� �ڱ� �ڽ� �ϳ��� �κ� ������ ���� �� �ֱ� ����.
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < i; ++j) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
				longestLength = max(longestLength, dp[i]);
			}
		}
	}

	stack<int> s;
	for (int i = N - 1; i >= 0; --i) {
		if (longestLength == dp[i]) {
			s.push(arr[i]);
			longestLength--;
		}
	}
	cout << s.size() << '\n';
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	cout << '\n';
	return 0;
}