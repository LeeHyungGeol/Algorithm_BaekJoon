// ������(prefix sum) ����
// �Է� ���� ������ ���� �̸� ���س��� ���س��� ���� �̿��� �������� ���ϴ� �˰���

// PrefixSum[i][j] : (0,0) ~ (i,j) ������ ������ ��
// value : 1~N ������ ���� �ȿ��� (i,j)~(i+k, j+k)�� ���簢���� �� ����

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MIN -1e9

int N;
vector<vector<int>> Apples;
vector<vector<int>> PrefixSum;

int main() {
	cin >> N;

	Apples.resize(N, vector<int>(N, 0));
	PrefixSum.resize(N + 1, vector<int>(N + 1, 0));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> Apples[i][j];
			PrefixSum[i + 1][j + 1] = PrefixSum[i][j + 1] + PrefixSum[i + 1][j] - PrefixSum[i][j] + Apples[i][j];
		}
	}

	int answer = MIN; // answer = PrefixSum[1][1];

	for (int k = 1; k <= N; ++k) {
		for (int i = 0; i + k <= N; ++i) {
			for (int j = 0; j + k <= N; ++j) {
				int value = PrefixSum[i + k][j + k] - PrefixSum[i + k][j] - PrefixSum[i][j + k] + PrefixSum[i][j];
				answer = max(answer, value);
			}
		}
	}

	cout << answer << '\n';

	return 0;
}