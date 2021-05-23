// �������� �̺� Ž���� �̿��� �Ķ��Ʈ�� ��ġ ����
// (1 �� N �� 1,000,000, 1 �� M �� 2,000,000,000)
// ������ ������ 10���̳� �Ǳ� ������, �̺� Ž���� ������ �� �־�� �Ѵ�.

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
		
		// �ڸ��� ���̸� ���� �����Ͽ� ������ �� �ִ� ������ M���� �����Ƿ�
		// end�� �� �۰� �����Ѵ�. (���� �κ� Ž��)
		if (sum < M) {
			end = mid - 1;
		}
		// ������ ���� M�̻��� ��� �� �ڸ��� (������ �κ� Ž��)
		else {
			// ������ �� �ִ� ������ �ִ��̶�� �����Ƿ�, ���⿡ result�� ����Ѵ�.
			result = mid;
			start = mid + 1;
		}
	}

	cout << result << '\n';

	return 0;
}