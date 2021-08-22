#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1e9

using namespace std;

int N, K, Answer = MAX;
vector<int> Arr;

int main() {
	cin >> N >> K;

	for (int i = 1; i <= N; ++i) {
		int x;
		cin >> x;
		if (x == 1) {
			Arr.push_back(i);
		}
	}

	if ((int)Arr.size() < K) {
		cout << "-1" << '\n';
		return 0;
	}

	for (int i = 0; i <= Arr.size() - K; ++i) {
		int value = Arr[i + K - 1] - Arr[i] + 1;
		Answer = min(Answer, value);
	}
	
	cout << Answer << '\n';
	
	return 0;
}