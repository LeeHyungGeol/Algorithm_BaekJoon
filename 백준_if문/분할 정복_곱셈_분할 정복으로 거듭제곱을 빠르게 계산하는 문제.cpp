//분할 정복으로 거듭제곱을 빠르게 계산하는 문제
#include <iostream>
using namespace std;
long long int divideAndConquer(int a, int b, int c);

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long int A, B, C, answer = 0;
	cin >> A >> B >> C;

	answer = divideAndConquer(A, B, C);
	cout << answer << '\n';
	return 0;
}
long long int divideAndConquer(int a, int b, int c) {
	if (b == 0)
		return 1;
	if (b % 2 == 1)
		return (a * (divideAndConquer(a, b - 1, c))) % c;
	else {
		long long int half = divideAndConquer(a, b / 2,c);
		return (half * half) % c;
	}
}

