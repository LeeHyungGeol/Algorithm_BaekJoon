#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main() {

	string str;
	int sum = 0, N;

	cin >> N;
	cin >> str;

	for (int i = 0; i < N; i++) {
		sum += str[i] - '0'; //���� 0('0')�� ���ָ� ���ڰ� ���´�.
	}
	cout << sum << '\n';
	return 0;
}