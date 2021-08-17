// �̺� Ž��(�Ķ��Ʈ�� ��ġ) ����

// 0�п��� M��ŭ�� ����� ź��.
// A ���̱ⱸ�� mid �б��� �� ���� �¿�°�? : mid / (A�� ����ð�)
// K�п� �� ���� ���̱ⱸ�� ���� �����Ѱ�? : K % Times[i](������ ���̱ⱸ�� ����ð�) == 0 �� ������ ī��Ʈ

// https://suhwanc.tistory.com/45
// http://melonicedlatte.com/algorithm/2018/08/09/115053.html

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

ll N, M, Answer, TotalTime;
vector<ll> Times;

int main() {
	cin >> N >> M;

	for (int i = 0; i < M; ++i) {
		int time;
		cin >> time;
		Times.push_back(time);
	}

	if (N <= M) {
		cout << N << '\n';
		return 0;
	}

	ll start = 0, end = 60000000000;

	while (start <= end) {
		ll mid = (start + end) / 2;
		ll totalChildren = M;

		for (int i = 0; i < Times.size(); ++i) {
			totalChildren += mid / Times[i];
		}

		if (totalChildren < N) {
			start = mid + 1;
		}
		else {
			TotalTime = mid;
			end = mid - 1;
		}
	}

	ll children = M;

	for (int i = 0; i < Times.size(); ++i) {
		children += (TotalTime - 1) / Times[i];
	}

	for (int i = 0; i < Times.size(); ++i) {
		if (TotalTime % Times[i] == 0) {
			++children;
		}
		if (children == N) {
			cout << i + 1 << '\n';
			break;
		}
	}

	return 0;
}
