//�迭�� ������ �� �̺� Ž������ ���� ã�� ���ô�.
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
	vector<int> v;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	cin >> M;
	for (int i = 0; i < M; ++i) {
		cin >> x;
		if (countByRange(v, x, x) != 0)
			cout << countByRange(v, x, x) << ' ';
		else
			cout << "0" << ' ';
	}
	cout << '\n';
	return 0;
}
// ���� [left_value, right_value]�� �������� ������ ��ȯ�ϴ� �Լ�
int countByRange(vector<int>& v, int leftValue, int rightValue) {
	vector<int>::iterator leftIndex = lower_bound(v.begin(), v.end(), leftValue);
	vector<int>::iterator rightIndex = upper_bound(v.begin(), v.end(), rightValue);

	return rightIndex - leftIndex;
}