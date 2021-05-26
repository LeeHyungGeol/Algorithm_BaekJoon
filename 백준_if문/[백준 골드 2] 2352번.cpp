// 이분 탐색을 이용한 `가장 긴 증가하는 부분 수열(LIS)` 문제
// C++의 STL라이브러리인 <algorithm>에 포함된 함수인 lower_bound()를 구현하거나 라이브러리를 사용하여 해결한다. 

// [백준 골드 2] 12015번 : 가장 긴 증가하는 부분 수열2 의 문제와 똑같다.
// 단, 가장 긴 증가하는 부분 수열의 크기만 구해줄 뿐, 그 구성 요소들이 가장 긴 증가하는 부분 수열과 같지는 않다는 사실에 주의하자!!
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, cnt = 0;
vector<int> port;

int first(vector<int>& arr, int target, int start, int end);

int main() {
	cin >> N;

	// 차례로 1번 포트와 연결되어야 하는 포트 번호, 
	// 2번 포트와 연결되어야 하는 포트 번호, …, 
	// n번 포트와 연결되어야 하는 포트 번호가 주어진다.
	// 이 수들은 1 이상 n 이하이며 서로 같은 수는 없다고 가정하자.

	// 수들이 1 이상 n 이하라고 하였으므로, 상대적으로 가장 작은 수인 -1 을 입력해둔다.
	port.push_back(-1);

	for (int i = 0; i < N; ++i) {
		int temp;
		cin >> temp;

		if (port.back() < temp) {
			port.push_back(temp);
			++cnt;
		}
		else {
			int index = first(port, temp, 0, port.size() - 1);
			//int index = lower_bound(port.begin(), port.end(), temp) - port.begin();
			port[index] = temp;
		}
	}

	cout << cnt << '\n';

	return 0;
}

int first(vector<int>& arr, int target, int start, int end) {
	if (start > end) {
		return start;
	}

	int mid = (start + end) / 2;

	// 왼쪽 부분 탐색
	if (arr[mid] >= target) {
		return first(arr, target, start, mid - 1);
	}
	// 오른쪽 부분 탐색
	else {
		return first(arr, target, mid + 1, end);
	}
}