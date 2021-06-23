#include <iostream>
#include <string>

using namespace std;

int Left, Right;
string N;

int main() {
	cin >> N;

	for (int i = 0; i < (N.size() / 2); ++i) {
		Left += N[i] - '0';
	}

	for (int i = (N.size() / 2); i < N.size(); ++i) {
		Right += N[i] - '0';
	}
	
	if (Left == Right) {
		cout << "LUCKY" << '\n';
	}
	else {
		cout << "READY" << '\n';
	}

	return 0;
}