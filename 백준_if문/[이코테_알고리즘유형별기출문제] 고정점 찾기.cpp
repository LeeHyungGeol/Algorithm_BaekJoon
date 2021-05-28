// 이분 탐색 문제
// 입력 값들의 모든 원소가 오름차순으로 이미 오름차순으로 정렬되어 있기 때문에 이분탐색을 수행 가능하다.
// 시간 복잡도 제한이 O(logN)이기 때문에, 선형 탐색으로 해결이 불가능하고 이분탐색을 수행해야만 통과 가능하다.

// 고정점 : 배열의 원소 중에서 그 값이 인덱스와 동일한 원소

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> arr;

int binarySearch(vector<int>& arr, int start, int end);

int main() {
	cin >> N;

	for (int i = 0; i < N; ++i) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}

	int result = binarySearch(arr, 0, arr.size() - 1);

	cout << result << '\n';

	return 0;
}

int binarySearch(vector<int>& arr, int start, int end) {
	if (start > end) {
		return -1;
	}

	int mid = (start + end) / 2;

	if (arr[mid] == mid) {
		return mid;
	}
	else if (arr[mid] > mid) {
		return binarySearch(arr, start, mid - 1);
	}
	else {
		return binarySearch(arr, mid + 1, end);
	}
}
