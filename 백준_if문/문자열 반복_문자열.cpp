#include <iostream>
#include <string>
using namespace std;

int main() {

	string S;
	int T, R;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> R;
		cin >> S;
		for (int j = 0; j < S.size(); j++) {
			for (int k = 0; k < R; k++) {
				cout << S[j];
			}
		}
		cout << '\n';
	}

	return 0;
}