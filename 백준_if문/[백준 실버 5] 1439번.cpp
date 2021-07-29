// �׸���(Ž���)
// ���� ���� �ִ� ���ڿ� �ٷ� ��ĭ �ڿ� ������ ���ڰ� �ٸ� ��,
// ���� ���� �ִ� ���ڰ� 0���� 1������ �����Ͽ� 0�� �������� 1�� �������� ������ count�ϰ�
// �� �� ���� ���ڸ� �������� ����Ѵ�.

// �򰥷ȴ� �κ� : �Ǹ����� ������ ��� C++�� ���ڿ� �������� 'NULL����'�� �����Ƿ�, 
// ������ ���ڿ��� ����(00.. Ȥ�� 11..) �� �����Ͽ� count�� �� �ִ�.

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str;

int main() {
	cin >> str;

	int cnt0  = 0, cnt1 = 0;

	for (int i = 0; i < str.length(); ++i) {
		int after = str[i+1] - '0';
		int now = str[i] - '0';

		if (after != now) {
			if (now == 0) {
				++cnt0;
			}
			else {
				++cnt1;
			}
		}
	}

	cout << min(cnt0, cnt1) << '\n';

	return 0;
}