// ���� ����, �׸��� ����
// �� å���� ��ġ�� ���, ������ ������ �迭�� �Է� ���� ��, 
// ���� �� å��(M��)�� �����ϰ�, ���ʷ� å�� ������ ���´�.

// �Է� ���� ���� ���� ����̰ų� ������ �� �ִ�!!

#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

typedef long long ll;

int N, M;
deque<ll> dq;

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		ll temp;
		cin >> temp;
		dq.push_back(temp);
	}

	sort(dq.begin(), dq.end());

	long long sum = 0;
	ll Max = max(dq.back(), abs(dq.front()));

	// �Է� ���� ���� ���� ����̰ų� ������ �� �ִ�!!

	while (!dq.empty()) {
		if (dq.back() < 0) {
			break;
		}

		bool flag = false;
		sum += dq.back() * 2;
		
		// ���ǹ��� ����� ���� �׻� �켱 ���ǹ��� ��������!!
		// ���ǹ��� ���ǹ� �񱳸� ���������� �����Ѵ�.
		for (int i = 0; i < M; ++i) {
			if (dq.empty() || dq.back() < 0) {
				flag = true;
				break;
			}
			dq.pop_back();
		}

		if (flag) {
			break;
		}
	}

	while (!dq.empty()) {
		if (dq.front() > 0) {
			break;
		}

		bool flag = false;
		sum += abs(dq.front()) * 2;

		// ���ǹ��� ����� ���� �׻� �켱 ���ǹ��� ��������!!
		// ���ǹ��� ���ǹ� �񱳸� ���������� �����Ѵ�.
		for (int i = 0; i < M; ++i) {
			if (dq.empty() || dq.front() > 0) {
				flag = true;
				break;
			}
			dq.pop_front();
		}

		if (flag) {
			break;
		}
	}

	cout << sum - Max << '\n';

	return 0;
}