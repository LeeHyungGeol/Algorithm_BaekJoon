#include <iostream>
#include <vector>

using namespace std;

int N, M, R;
vector<vector<int>> Arr;

void rotate(vector<vector<int>>& arr);

int main() {
	cin >> N >> M >> R;

	Arr.resize(N, vector<int>(M, 0));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> Arr[i][j];
		}
	}

	while (R--) {
		rotate(Arr);
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << Arr[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}

void rotate(vector<vector<int>>& arr) {
	int x = 0, y = 0;
	int endX = arr.size() - 1, endY = arr[0].size() - 1;



}