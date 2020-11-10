// 행렬 곱셈을 응용해 피보나치 수를 구하는 문제
// 지역 변수는 힙 메모리를 사용하고 전역 변수는 스택 메모리를 사용한다.
// "피사노 주기를 이용한다" -> 모르면 못 푸는 문제..
// 피보나치 수열을 m으로 나눈 나머지는 주기를 이룬다.
// 나머지를 이용해서 만든 수열은 주기가 나타날 수 있다. 
// k(m)을 반복하는 부분 수열의 길이라고 했을 때, k(11) = 10임을 알 수 있다.
// n > 2라면, k(10^n) = 15×10^(n-1)
#include <iostream>
using namespace std;
#define mod 1000000 
#define period 1500000
int dp[15000001] = { 0,1, };
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long n;
	cin >> n;
	for (int i = 2; i <= period; ++i) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
	}
	cout << dp[n % period] << '\n';

	return 0;
}