// 그리디(탐욕법), 수학 문제

#include <iostream>

using namespace std;

typedef long long ll;

ll S, sum;

int main() {
	cin >> S;

	for (ll i = 1; i <= S; ++i) {
		sum += i;
		if (sum == S) {
			cout << i << '\n';
			break;
		}
		else if (sum > S) {
			cout << i - 1 << '\n';
			break;
		}
	}

	return 0;
}