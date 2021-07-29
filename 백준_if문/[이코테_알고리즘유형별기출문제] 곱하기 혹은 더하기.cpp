// �׸���(Ž���) ����
// 1. �� ó�� ���ڰ� 0 Ȥ�� 1
// 2. ���ݱ����� �� ���� 0 Ȥ�� 1
// �� 2������ ����� �� ���ڸ� ���ϰ� �������� ���ϸ� �ȴ�.

#include <iostream>
#include <string>

using namespace std;

long long sum;
string str;

int main() {
	cin >> str;

	sum = str[0] - '0';

	for (int i = 1; i < str.length(); ++i) {
		int now = str[i] - '0';
		
		if (sum == 0 || sum == 1 || now == 0 || now == 1) {
			sum += now;
		}
		else {
			sum *= now;
		}
	}

	cout << sum << '\n';

	return 0;
}