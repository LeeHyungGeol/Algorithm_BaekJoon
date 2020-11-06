#include <iostream>
using namespace std;
int arr1[101][101] = { 0 };
int arr2[101][101] = { 0 };
int answer[101][101] = { 0 };
int main() {

	int N, M, K;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> arr1[i][j];
		}
	}
	cin >> M >> K;
	for (int i = 1; i <= M; ++i) {
		for (int j = 1; j <= K; ++j) {
			cin >> arr2[i][j];
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			for (int k = 1; k <= K; ++k) {
				answer[i][k] += arr1[i][j] * arr2[j][k];
			}
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= K; ++j) {
			cout << answer[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}