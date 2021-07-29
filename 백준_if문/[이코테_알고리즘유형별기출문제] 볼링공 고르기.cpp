// �׸���(Ž���)
// ù ��° Ǯ�� : 2�� �ݺ����� �̿��Ͽ� ��� ������ ���� count�Ͽ���.
// �� ��° Ǯ��(���� Ǯ��) : �������� ���԰� 1~10 ���� ������ �ֱ� ������
// �ݺ����� 1���� ���鼭 ������ �������� ������� ���ϸ鼭 ������ ������ ��� �����ϴ�.

#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int N, M;
vector<pii> balls;
// ���԰� 1~10�� �������� ������ �ٴ� �迭
int weights[11] = { 0, };

void solution1();
void solution2();

int main() {

	//solution1();

	solution2();

	return 0;
}

void solution1() {
	cin >> N >> M;

	balls.resize(N, { 0,0 });

	for (int i = 0; i < N; ++i) {
		int weight;
		cin >> weight;
		balls[i] = { i + 1, weight };
	}

	int cnt = 0;

	for (int i = 0; i < N - 1; ++i) {
		for (int j = i + 1; j < N; ++j) {
			if (balls[i].second != balls[j].second) {
				++cnt;
			}
		}
	}

	cout << cnt << '\n';
}

void solution2() {
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		int w;
		cin >> w;
		++weights[w];
	}

	int cnt = 0;

	// ���԰� 1���� M���� ������ �������� ���� ó��
	for (int i = 1; i <= M; ++i) {
		// ���԰� i�� �������� ����(A�� ������ �� �ִ� ���� ����)
		N -= weights[i];
		// A�� ������ ����� ��(weights[i])�� B�� �����ϴ� ����� ��(N) ���ϱ�
		cnt += weights[i] * N;
	}

	cout << cnt << '\n';
}