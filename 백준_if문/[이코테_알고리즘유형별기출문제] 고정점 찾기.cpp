// �̺� Ž�� ����
// �Է� ������ ��� ���Ұ� ������������ �̹� ������������ ���ĵǾ� �ֱ� ������ �̺�Ž���� ���� �����ϴ�.
// �ð� ���⵵ ������ O(logN)�̱� ������, ���� Ž������ �ذ��� �Ұ����ϰ� �̺�Ž���� �����ؾ߸� ��� �����ϴ�.

// ������ : �迭�� ���� �߿��� �� ���� �ε����� ������ ����

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
