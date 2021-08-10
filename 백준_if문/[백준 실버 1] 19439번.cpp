#include<iostream>
using namespace std;

int N, sum, sum_2;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		sum += a;
		sum_2 += (a / 2);

	}
	if (sum % 3 == 0) {
		if (sum_2 >= (sum / 3)) {
			cout << "YES\n";
			return 0;
		}
		else {
			cout << "NO\n";
			return 0;
		}
	}
	else {
		cout << "NO\n";
	}
}