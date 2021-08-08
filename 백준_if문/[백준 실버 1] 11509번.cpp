#include <iostream>
#include <vector>

using namespace std;

int N, Answer;
vector<int> Heights;

int main() {
	cin >> N;

	Heights.resize(1000001, 0);
	
	int h = 0;

	for (int i = 0; i < N; ++i) {
		cin >> h;
		if (Heights[h] == 0) {
			++Heights[h - 1];
			++Answer;
		}
		else {
			--Heights[h];
			++Heights[h - 1];
		}
	}
	
	cout << Answer << '\n';

	return 0;
}