// �׸���(Ž���), ���� ����

// �׸����� �����ϴ� ���� �������. 

// �ѹ��� �� ������ ���̸� 3��ŭ �����ų �� �ִٰ� �����Ƿ�,
// �� ������ ���̴� 3�� ����̾�߸� �Ѵ�.(if(sum3 % 3 == 0))

// �׸���, �� n�� ���� �ѷȴٸ�, 2��ŭ n��, 1��ŭ n�� �ѷȴٴ� �ǹ��̰�,
// �� ������ ���̿��� 2�� ���� �͵��� ��(sum2 += x / 2)�� �� n��(sum3 / 3) ���� ũ�ų� ������ �ȴ�.

// ���� : https://velog.io/@axiom0510/b19539

#include <iostream>

using namespace std;

int N, sum2, sum3;

int main() {
	cin >> N;

	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		sum3 += x;
		sum2 += x / 2;
	}

	if (sum3 % 3 == 0) {
		if (sum2 >= (sum3 / 3)) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}
	else {
		cout << "NO" << '\n';
	}

	return 0;
}