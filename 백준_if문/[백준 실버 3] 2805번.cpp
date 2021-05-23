// 전형적인 이분 탐색을 이용한 파라메트릭 서치 문제
// (1 ≤ N ≤ 1,000,000, 1 ≤ M ≤ 2,000,000,000)
// 범위의 단위가 10억이나 되기 때문에, 이분 탐색을 생각할 수 있어야 한다.

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1e9

using namespace std;

typedef long long int ll;

int N, M;
vector<int> tree;

int main() {	
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		int height;
		cin >> height;
		tree.push_back(height);
	}

	int start = 1;
	int end = MAX;
	ll result = 0;

	while (start <= end) {
		ll sum = 0;

		int mid = (start + end) / 2;

		for (int i = 0; i < N; ++i) {
			if (tree[i] > mid) {
				sum += tree[i] - mid;
			}
		}
		
		// 자르는 높이를 높게 설정하여 가져갈 수 있는 나무가 M보다 작으므로
		// end를 더 작게 설정한다. (왼쪽 부분 탐색)
		if (sum < M) {
			end = mid - 1;
		}
		// 나무의 양이 M이상인 경우 덜 자르기 (오른쪽 부분 탐색)
		else {
			// 설정할 수 있는 높이의 최댓값이라고 했으므로, 여기에 result를 기록한다.
			result = mid;
			start = mid + 1;
		}
	}

	cout << result << '\n';

	return 0;
}