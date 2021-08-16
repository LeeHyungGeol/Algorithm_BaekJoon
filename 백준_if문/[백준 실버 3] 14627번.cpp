// �̺�Ž��(�Ķ��Ʈ�� ��ġ) ����

// ������ ������ �� �ľ��ϴ� ���� ���� �߿��ϴ�.
// �Է��� ������ ����� ũ�� ������ long long Ÿ������ �����ϰ� �����ϴ� ���� ����.
// start = 1 �� �ʱ�ȭ �ؾ� �ϴ� �͵� ���� ����!!

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll S, C, Sum;
vector<ll> Arr;

int main() {
	cin >> S >> C;

	for (int i = 0; i < S; ++i) {
		ll x;
		cin >> x;
		Arr.push_back(x);
		Sum += x;
	}

	ll start = 1, end = 1000000000, result = 0;

	while (start <= end) {
		ll mid = (start + end) / 2;

		ll total = 0;

		for (int i = 0; i < Arr.size(); ++i) {
			total += (Arr[i] / mid);
		}

		if (total < C) {
			end = mid - 1;
		}
		else {
			result = mid;			
			start = mid + 1;
		}
	}

	cout << Sum - (result * C) << '\n';

	return 0;
}