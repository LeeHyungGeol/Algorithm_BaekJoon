// 그리디(탐욕법) 문제
// 1. 맨 처음 숫자가 0 혹은 1
// 2. 지금까지의 총 합이 0 혹은 1
// 이 2가지의 경우일 때 숫자를 더하고 나머지는 곱하면 된다.

#include <iostream>
#include <string>

using namespace std;

long long sum;
string str;

int main() {
	cin >> str;

	sum = str[0] - '0';

	for (int i = 1; i < str.length(); ++i) {
		int now = str[i] - '0';
		
		if (sum == 0 || sum == 1 || now == 0 || now == 1) {
			sum += now;
		}
		else {
			sum *= now;
		}
	}

	cout << sum << '\n';

	return 0;
}