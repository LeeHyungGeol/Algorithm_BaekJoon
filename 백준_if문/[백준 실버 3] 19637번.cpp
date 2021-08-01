// 이분탐색 문제
// 조건들을 입력 받고, 그에 대한 lower_bound()를 구해서 그 index에 맞는 값을 출력한다.

// lower_bound() : 찾으려는 key 값보다 같거나 큰 숫자 가 배열 몇 번째에서 처음 등장 하는지 찾기 위함
// lower_bound()를 직접 구현해도 된다.

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int N, M;
vector<string> Names;
vector<int> Limits;

int first(const vector<int>& arr, int target, int start, int end);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		string name;
		int limit;
		cin >> name >> limit;
		Names.push_back(name);
		Limits.push_back(limit);
	}

	for (int i = 0; i < M; ++i) {
		int num;
		cin >> num;
		// int index = lower_bound(Limits.begin(), Limits.end(), num) - Limits.begin();
		int index = first(Limits, num, 0, Limits.size() - 1);
		cout << index << '\n' << '\n';
		//cout << Names[index] << '\n';
	}

	return 0;
}

int first(const vector<int>& arr, int target, int start, int end) {
	if (start > end) {
		return start;
	}

	int mid = (start + end) / 2;

	if (arr[mid] >= target) {
		return first(arr, target, start, mid - 1);
	}
	else {
		return first(arr, target, mid + 1, end);
	}
}
