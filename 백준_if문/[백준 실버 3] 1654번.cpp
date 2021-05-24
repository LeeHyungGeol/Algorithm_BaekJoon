// �̺� Ž���� �̿��� �Ķ��Ʈ�� ��ġ ����
// �Ķ��Ʈ�� ��ġ(Parametric Search) : ����ȭ ������ ���� ������ �ٲپ� �ذ��ϴ� ���
// -> �̺� Ž������ ���� ������ �ذ��ϸ鼭 ������ ������ �� �ִ�.

// K���� �������� N���� ������ �����.
// N������ ���� ����� �͵� N���� ����� �Ϳ� ���Եȴ�.
// �ִ� ������ ���̸� ������.


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;

int K, N;
vector<int> lanWire;

int main() {
	cin >> K >> N;

	for (int i = 0; i < K; ++i) {
		int temp;
		cin >> temp;
		lanWire.push_back(temp);
	}

	ll start = 0;
	ll end = 2147483647;
	ll result = 0;

	while (start <= end) {
		ll sum = 0;

		ll mid = (start + end) / 2;

		for (int i = 0; i < K; ++i) {
			ll count = lanWire[i] / mid;
			
			if (count) {
				sum += count;
			}
		}

		// N�� ���� �۴ٴ� �ǹ̴� ����(mid)�� �ʹ� ũ�� ���ؼ� ������ ���� �� �߶� �߻��� ���̹Ƿ�
		// (���� �κ� Ž��)�� �ǹ�
		if(sum < N) {
			end = mid - 1;
		}
		else {
			result = mid;
			start = mid + 1;
		}
	}

	cout << result << '\n';

	return 0;
}