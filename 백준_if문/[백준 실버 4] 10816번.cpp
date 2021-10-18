#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> Arr;

int countByRange(vector<int>& arr, int leftValue, int rightValue);

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	Arr.assign(N, 0);

	for (int i = 0; i < N; ++i) {
		cin >> Arr[i];
	}

	sort(Arr.begin(), Arr.end());

	cin >> M;

	for (int i = 0; i < M; ++i) {
		int n;
		cin >> n;
		cout << countByRange(Arr, n, n) << ' ';
	}

	return 0;
}

int countByRange(vector<int>& arr, int leftValue, int rightValue) {
	int left = lower_bound(arr.begin(), arr.end(), leftValue) - arr.begin();
	int right = upper_bound(arr.begin(), arr.end(), rightValue) - arr.begin();
	return right - left;
}