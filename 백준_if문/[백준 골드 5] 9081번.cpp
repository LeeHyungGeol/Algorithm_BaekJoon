#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int T;
string Str, Answer;

int main() {
	cin >> T;

	for (int t = 0; t < T; ++t) {
		cin >> Str;

		int cnt = 0;

		do {
			Answer = Str;
			if (++cnt == 2) {
				break;
			}
		} while (next_permutation(Str.begin(), Str.end()));


		cout << Answer << '\n';
	}

	return 0;
}