#include <iostream>
#include <string>

using namespace std;

int N, Answer;
string str;

int main() {
	cin >> N >> str;

	for (int i = 0; i < str.length(); ++i) {
		Answer += str[i] - '0';
	}

	cout << Answer << '\n';

	return 0;
}