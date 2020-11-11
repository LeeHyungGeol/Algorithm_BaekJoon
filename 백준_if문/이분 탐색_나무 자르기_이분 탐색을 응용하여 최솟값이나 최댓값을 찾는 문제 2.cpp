//�̺� Ž���� �����Ͽ� �ּڰ��̳� �ִ��� ã�� ���� 2
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<long long int> v;
	int N, M, x;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> x;
		v.push_back(x);
	}

	long long int start = 0, end = 1000000000;//���̴� 1000000000���� �۰ų� ���� ���� ���� �Ǵ� 0�̴�.
	long long int result = 0, cnt = 0;
	while (start <= end) {
		cnt = 0;
		long long int mid = (start + end) / 2;
		for (int i = 0; i < N; ++i) {
			if (v[i] > mid)
				cnt += (v[i] - mid);
		}
		if (cnt < M)
			end = mid - 1;
		else {
			result = mid;
			start = mid + 1;
		}
	}
	cout << result << '\n';
	return 0;
}