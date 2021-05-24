#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, x;
vector<int> arr;

int countByValue(vector<int>& arr, int target);
int first(vector<int>& arr, int target, int start, int end);
int last(vector<int>& arr, int target, int start, int end);

int main() {
	cin >> N >> x;

	for (int i = 0; i < N; ++i) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}

	int count = countByValue(arr, x);

	if (count == -1) {
		cout << "-1" << '\n';
	}
	else {
		cout << count << '\n';
	}

	return 0;
}

int countByValue(vector<int>& arr, int target) {
	int leftIndex = first(arr, target, 0, N - 1);

	if (leftIndex == -1) {
		return -1;
	}

	int rightIndex = last(arr, target, 0, N - 1);

	return rightIndex - leftIndex + 1;
}

int first(vector<int>& arr, int target, int start, int end) {
	if (start > end) {
		return -1;
	}

	int mid = (start + end) / 2;

	if (arr[mid] == target && (mid == 0 || arr[mid - 1] < target)) {
		return mid;
	}
	else if (arr[mid] >= target) {
		return first(arr, target, start, mid - 1);
	}
	else {
		return first(arr, target, mid + 1, end);
	}
}

int last(vector<int>& arr, int target, int start, int end) {
	if (start > end) {
		return -1;
	}

	int mid = (start + end) / 2;

	if (arr[mid] == target && (mid == N - 1 || arr[mid + 1] > target)) {
		return mid;
	}
	else if (arr[mid] > target) {
		return last(arr, target, start, mid - 1);
	}
	else {
		return last(arr, target, mid + 1, end);
	}
}