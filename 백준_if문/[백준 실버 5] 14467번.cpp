#include <iostream>
#include <vector>

using namespace std;

int N, Answer;
vector<int> Arr;

int main() {
	cin >> N;

	Arr.assign(11, -1);

	for (int i = 0; i < N; ++i) {
		int a, b;
		cin >> a >> b;
		if (Arr[a] == -1) Arr[a] = b;
		else {
			if (Arr[a] == b) continue;
			else ++Answer;
		}
	}

	cout << Answer << '\n';
	
	return 0;
}