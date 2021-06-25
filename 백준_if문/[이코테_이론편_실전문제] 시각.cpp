// 구현, 완전 탐색 문제

#include <iostream>
#include <string>

using namespace std;

int N;

bool check(int h, int m, int s);

int main() {
	cin >> N;

	int count = 0;
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j < 60; ++j) {
			for (int k = 0; k < 60; ++k) {
				/*string time = to_string(i) + to_string(j) + to_string(k);

				if (time.find('3') != string::npos) {
					++count;
				}*/
				if (check(i, j, k)) {
					++count;
				}
			}
		}
	}
	cout << count << '\n';

	return 0;
}

bool check(int h, int m, int s) {
	if (h % 10 == 3 || m % 10 == 3 || m / 10 == 3 || s % 10 == 3 || s / 10 == 3) {
		return true;
	}
	return false;
}