#include <iostream>
#include <string>

using namespace std;

int Answer;
int Count[] = { 3, 2, 1, 2,	3, 3, 3, 3, 1, 1, 3, 1, 3, 3, 1, 2, 2, 2, 1, 2, 1, 1, 2, 2, 2, 1 };
string Str;

int main() {
	cin >> Str;

	for (auto c : Str) {
		Answer += Count[c - 'A'];
	}

	if (Answer % 2) {
		cout << "I'm a winner!" << '\n';
	}
	else {
		cout << "You're the winner?" << '\n';
	}
	return 0;
}