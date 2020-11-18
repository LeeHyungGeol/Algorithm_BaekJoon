//다이나믹 프로그래밍(Dynamic Programming): 동적 계획법 - "중복되는 연산을 줄이자"
// 1. 큰 문제를 작은 문제로 나눌 수 있다.
// 2. 작은 문제에서 구한 정답은 그것을 포함하는 큰 문제에서도 동일하다.
//더 이상 사용되지 않는 값을 버림으로써 공간 복잡도를 향상시키는 문제. 메모리 제한에 주목.
//https://yabmoons.tistory.com/491 
#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;//동전의 가치
//int dp[100001] = { 0 };
int main() {
	
	int n, k, x;
	cin >> n >> k;//동전의 갯수, k만큼의 가치
	for (int i = 0; i < n; ++i) {
		cin >> x;
		arr.push_back(x);
	}
	vector<int> dp(k + 1, 0);
	dp[0] = 1;//동전들을 사용해서 0원을 만들 수 있는 경우는 몇 가지 -> 아무런 동전도 사용하지 않는 1가지 방법이 있다.
	for (int i = 0; i < n; ++i) {
		for (int j = arr[i]; j <= k; ++j) {
			//if (j >= arr[i])
				dp[j] += dp[j - arr[i]];
		}
	}
	cout << dp[k] << '\n';
	return 0;
}