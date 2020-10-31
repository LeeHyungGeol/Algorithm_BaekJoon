//LIS(Longest Increasing Subsequence) 가장 긴 증가하는 부분 수열 응용 문제
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//bottom-up방식
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
	//reverse(v.begin(), v.end()); //reverse를 썼을 때는 왜 안되지?
	//reverse를 하면 안되는 이유: reverse를 하면 index순서도 다 바뀌어 버리기 때문에 중복되는 index가 달라지기 때문에
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