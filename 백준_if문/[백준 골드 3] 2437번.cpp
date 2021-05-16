// 측정할 수 없는 양의 정수 무게 중 최솟값
// 각 무게 당 추를 하나씩만 사용해야 한다.

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

	// 더한 값을 저장?
	for (int i = 0; i < N; ++i) {
		if (result < scaleWeight[i]) {
			break;
		}

		result += scaleWeight[i];
	}

	cout << result << '\n';

	return 0;
}