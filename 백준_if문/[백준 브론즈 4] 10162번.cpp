#include <iostream>
#include <vector>

using namespace std;

int T;
vector<int> Arr = { 300, 60, 10 };
vector<int> Answer;

int main() {
	cin >> T;

	if (T % 10 != 0) {
		cout << "-1" << '\n';
		return 0;
	}

	for (int t : Arr) {
		Answer.push_back(T / t);
		T %= t;
	}

	for (int n : Answer) {
		cout << n << '\n';
	}

	return 0;
}