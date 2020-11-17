//더 이상 사용되지 않는 값을 버림으로써 공간 복잡도를 향상시키는 문제. 메모리 제한에 주목.
//https://yabmoons.tistory.com/491 
#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;//동전의 가치
int dp[100001] = { 0 };
int main() {
	
	int n, k, x;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		arr.push_back(x);
	}
	dp[0] = 1;//동전들을 사용해서 0원을 만들 수 있는 경우는 몇 가지 -> 아무런 동전도 사용하지 않는 1가지 방법이 있다.
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j <= k; ++j) {
			if (j >= arr[i])
				dp[j] += dp[j - arr[i]];
		}
	}
	cout << dp[k] << '\n';
	return 0;
}