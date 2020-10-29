#include <iostream>
using namespace std;

int main() {
	int cnt0[41] = { 1,0, };
	int cnt1[41] = { 0,1, };
	int T, input;

	for (int i = 2; i <= 40; ++i) {
		cnt0[i] = cnt0[i - 1] + cnt0[i - 2];
		cnt1[i] = cnt1[i - 1] + cnt1[i - 2];
	}
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> input;
		cout << cnt0[input] << " " << cnt1[input] << '\n';
	}

	return 0;
}