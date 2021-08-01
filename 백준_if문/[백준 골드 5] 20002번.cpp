#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> Apples;
vector<vector<int>> Sum;

int main() {
	cin >> N;

	Apples.resize(N, vector<int>(N, 0));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> Apples[i][j];
		}
	}



	return 0;
}