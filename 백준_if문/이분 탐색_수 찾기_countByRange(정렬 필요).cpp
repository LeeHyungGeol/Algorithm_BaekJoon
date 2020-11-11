//배열을 정렬한 후 이분 탐색으로 값을 찾아 봅시다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countByRange(vector<int>& v, int leftValue, int rightValue);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, x;
	vector<int> v1, v2;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> x;
		v1.push_back(x);
	}
	sort(v1.begin(), v1.end());
	cin >> M;
	for (int i = 0; i < M; ++i) {
		cin >> x;
		v2.push_back(x);
	}
	
	for (int i = 0; i < M; ++i) {
		if (countByRange(v1, v2[i], v2[i]) != 0)
			cout << "1"<< '\n';
		else
			cout << "0" << '\n';
	}
	cout << '\n';
	return 0;
}
// 값이 [left_value, right_value]인 데이터의 개수를 반환하는 함수
int countByRange(vector<int>& v, int leftValue, int rightValue) {
	vector<int>::iterator leftIndex = lower_bound(v.begin(), v.end(), leftValue);
	vector<int>::iterator rightIndex = upper_bound(v.begin(), v.end(), rightValue);

	return rightIndex - leftIndex;
}