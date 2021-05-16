// ������ �� ���� ���� ���� ���� �� �ּڰ�
// �� ���� �� �߸� �ϳ����� ����ؾ� �Ѵ�.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, result = 1;
vector<int> scaleWeight;

int main() {

	cin >> N;

	scaleWeight.resize(N);

	for (int i = 0; i < N; ++i) {
		cin >> scaleWeight[i];
	}

	sort(scaleWeight.begin(), scaleWeight.end());

	// ���� ���� ����?
	for (int i = 0; i < N; ++i) {
		if (result < scaleWeight[i]) {
			break;
		}

		result += scaleWeight[i];
	}

	cout << result << '\n';

	return 0;
}