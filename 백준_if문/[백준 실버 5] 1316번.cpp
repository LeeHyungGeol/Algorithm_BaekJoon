#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, Count;
string str;

int main() {
	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> str;
		for (int j = 0; j < str.length(); ++j) {
			int index = str.find_last_of(str[i]);
			cout << index << '\n';
		}
	}


	return 0;
}