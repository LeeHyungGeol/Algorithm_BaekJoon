#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> arr;

int binarySearch(vector<int>& arr, int target, int start, int end);

int main() {
	cin >> N;

	for (int i = 0; i < N; ++i) {
		int n;
		cin >> n;
		arr.push_back(n);
	}

	cin >> M;

	for (int i = 0; i < M; ++i) {
		int target;
		cin >> target;
		int result = binarySearch(arr, target, 0, arr.size() - 1);
		if (result == -1) {
			cout << "no ";
		}
		else {
			cout << "yes ";
		}
	}
	cout << '\n';


	return 0;
}

int binarySearch(vector<int>& arr, int target, int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2;

		if (arr[mid] == target) {
			return mid;
		}
		else if (arr[mid] > target) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	
	return -1;
}