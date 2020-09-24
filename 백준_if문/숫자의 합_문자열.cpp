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
		sum += str[i] - '0'; //문자 0('0')을 빼주면 숫자가 나온다.
	}
	cout << sum << '\n';
	return 0;
}